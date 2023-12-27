/** Program that reads data from input file and parses it in order to create a new output file
 * with only the data from massachusetts towns/cities.
 *
 * @author Reda Boutayeb
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief Reads a comma-separated value (CSV) file and extracts the zip codes
 * and city names of all records in Massachusetts.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments, where argv[0] is the name of
 * the program, argv[1] is the name of the input file, and argv[2] is the name
 * of the output file.
 *
 * @return 0 if the program completes successfully, 1 otherwise.
 */


int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " input_file output_file" << endl;
        return 1;
    }

    string input_file_name = argv[1];
    string output_file_name = argv[2];

    ifstream input_file(input_file_name);
    ofstream output_file(output_file_name);

    if (!input_file.is_open()) {
        cout << "Failed to open input file: " << input_file_name << endl;
        return 1;
    }

    if (!output_file.is_open()) {
        cout << "Failed to open output file: " << output_file_name << endl;
        return 1;
    }

    string line;
    while (getline(input_file, line)) {
        // parse the line into fields
        stringstream ss(line);
        string record_number, zipcode, zip_type, city, state, location_type, lat, lng, xaxis, yaxis, zaxis, world_region, country, location_text, location, decommisioned, tax_returns_filed, est_population, total_wages, notes;
        getline(ss, record_number, ',');
        getline(ss, zipcode, ',');
        getline(ss, zip_type, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, location_type, ',');
        getline(ss, lat, ',');
        getline(ss, lng, ',');
        getline(ss, xaxis, ',');
        getline(ss, yaxis, ',');
        getline(ss, zaxis, ',');
        getline(ss, world_region, ',');
        getline(ss, country, ',');
        getline(ss, location_text, ',');
        getline(ss, location, ',');
        getline(ss, decommisioned, ',');
        getline(ss, tax_returns_filed, ',');
        getline(ss, est_population, ',');
        getline(ss, total_wages, ',');
        getline(ss, notes, ',');

        // check if the record is in Massachusetts and extract the city name
        if (state == "MA") {
            output_file << zipcode << "," << zip_type << "," << city << "," << state << "," << lat << "," << lng << endl;
        }
    }

    input_file.close();
    output_file.close();

    return 0;
}
  
  
  

  
