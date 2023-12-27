/** Program demonstrating parsing and linked lists. This program 
 * supports zip code lookup for any town in Massachusetts
 *
 * @author Reda Boutayeb
 *
 */

//Importing libraries

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "zipcode.h"

using namespace std;


/** program to find the zip code for any town in Massachusetts
 *
 * @param argc is the number of field on command line - should be 1
 * @param argv is array of strings entered on command line - prog name
 * @return 0 for success
 */



int main(int argc, char *argv[]) {


// Checking number of arguments, only have the file and the call command.
if (argc != 2) {
        cout << "Usage: " << argv[0] << " input_file " << endl;
        return 1;
    }



// Taking in the argument and passing in to main
 string input_file_name = argv[1];

//Defining the input file to use in program.


 ifstream input_file(input_file_name);
    
    // Error message given in case the program fails to open the file.
    if (!input_file.is_open()) {
        cout << "Failed to open input file: " << input_file_name << endl;
        return 1;
    }

        
    string line;
    
   //Creating a linked list with the Record struct created 

    Record* head = nullptr;
    Record* tail = nullptr;
    
    //Parsing the data using getline method, only 6 fields, zipcode, the type, city name, state, latitude and longitude.
    
    while (getline(input_file, line)) {
    // parse the line into fields
    stringstream ss(line);
    string zipcode, zip_type, city, state, lat, lng;
    getline(ss, zipcode, ',');
    getline(ss, zip_type, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    getline(ss, lat, ',');
    getline(ss, lng, ',');
 
    // create a new record and add it to the linked list
    Record* new_record = new Record(zipcode, zip_type, city, state, lat, lng);
    if (head == nullptr) {
        head = new_record;
        tail = new_record;
    } else {
        tail->next = new_record;
        tail = new_record;
    }   
} 
    
    // Sort the linked list alphabetically using the city name
    sortList(head);


    Record* current = head;
    
    //Prompt user to enter the name of a city in order to look it up, in order to terminate, CTRL-D.
    string city;
    while (cout << "Enter a city name (or Ctrl-D to exit): " && getline(cin, city)) {
        lookupZipcodes(city, head);
    }

    
    //Once done using the input file, close it.
    input_file.close();
    
    //Return 0 to indicate success.
    return 0;

}
