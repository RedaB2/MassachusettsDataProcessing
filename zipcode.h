/** Header file for zipcode and structure implementation
 *
 * @author Reda Boutayeb
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/**
 * @brief Struct representing a single record in a linked list of US zip code data.
 * This struct contains the following fields for a single zip code record:
 * zipcode: A string representing the 5-digit US zip code.
 * zip_type: A string indicating the type of the zip code, e.g. "STANDARD".
 * city: A string representing the name of the city associated with the zip code.
 * state: A string representing the two-letter abbreviation of the US state associated with the zip code.
 * lat: A string representing the latitude of the city associated with the zip code.
 * lng: A string representing the longitude of the city associated with the zip code.
 * next: A pointer to the next record in the linked list, or nullptr if this is the last record.
 * The struct also defines a constructor that takes the values for all fields as arguments.
*/

struct Record {
    string zipcode;
    string zip_type;
    string city;
    string state;
    string lat;
    string lng;
    Record* next;

    
    /**
     * @brief Constructor for a Record object.
     * @param zipcode A string representing the 5-digit US zip code.
     * @param zip_type A string indicating the type of the zip code, e.g. "STANDARD".
     * @param city A string representing the name of the city associated with the zip code.
     * @param state A string representing the two-letter abbreviation of the US state associated with the zip code.
     * @param lat A string representing the latitude of the city associated with the zip code.
     * @param lng A string representing the longitude of the city associated with the zip code.
    */
    
    Record(const string& zipcode, const string& zip_type, const string& city,
               const string& state, const string& lat, const string& lng) :
    zipcode(zipcode), zip_type(zip_type), city(city), state(state), lat(lat), lng(lng), next(nullptr) {
}
};

// Declaring functions

void sortList(Record* head);
void lookupZipcodes(const string& city, Record* head);


//Sorting function 

/**
 * @brief Sorts a linked list of Records alphabetically by city name.
 * 
 * @param head A pointer to the head node of the linked list to be sorted.
*/

void sortList(Record* head) {
    // Determine the number of nodes in the linked list
    int count = 0;
    Record* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    // Create an array to hold the pointers to the nodes
    Record** records = new Record*[count];

    // Copy the pointers to the nodes into the array
    curr = head;
    for (int i = 0; i < count; i++) {
        records[i] = curr;
        curr = curr->next;
    }

    // Sort the array by city name
    sort(records, records + count, [](Record* a, Record* b) {
        return a->city < b->city;
    });

    // Rebuild the linked list with the sorted nodes
    head = records[0];
    for (int i = 0; i < count - 1; i++) {
        records[i]->next = records[i+1];
    }
    records[count-1]->next = nullptr;

    // Free the memory used by the array
    delete[] records;
}


/**
 * @brief Searches the linked list of records for all zipcodes associated with the given city name.

 * @param city The name of the city to search for (case-insensitive)
 * @param head A pointer to the head of a linked list of Record objects
 * @return none
*/

void lookupZipcodes(const string& city, Record* head) {
    Record* current = head;
    bool found = false;
    while (current != nullptr) {
        // Convert both the input city name and the stored city names to lowercase
        string city_lower = city;
        std::transform(city_lower.begin(), city_lower.end(), city_lower.begin(), [](unsigned char c){ return std::tolower(c); });
        string stored_city_lower = current->city;
        std::transform(stored_city_lower.begin(), stored_city_lower.end(), stored_city_lower.begin(), [](unsigned char c){ return std::tolower(c); });

        if (stored_city_lower == city_lower) {
            cout << current->zipcode << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "No zipcodes found for city: " << city << endl;
    }
}