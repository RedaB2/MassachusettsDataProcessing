Reda Boutayeb
rboutayeb

In order to compile the program: 

- Open the terminal
- Make sure all the files are in the directory you are in, if not access it using cd. 
- Enter "make" in order to execute the makefile
- Enter "make docs" in order to make sure the webpage will work.
- Then, the program should be compiled, you can execute any program just by using the commands indicated.
- If you want to delete all the files, "make clean".

In this file, we have two programs: 

 - fed2cs2303
 - zipcode

 fed2cs2303: 

  Program that reads data from input file and parses it in order to create a new output file
  with only the data from massachusetts towns/cities.

 Example of usage: 

 ./fed2cs2303 input_file output_file 

 or 

 ./fed2cs2303 input_file "name_desired_for_new_output_file"

 zipcode: 

 Program demonstrating parsing and linked lists. This program supports zip code lookup for any town in Massachusetts.

 Example:

 ./zipcode "input_file"
