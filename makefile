
all: fed2cs2303 zipcode

fed2cs2303: fed2cs2303.o zipfed.o
	g++ -g fed2cs2303.o zipfed.o -o fed2cs2303

fed2cs2303.o: fed2cs2303.c zipfed.hpp
	g++ -g -c fed2cs2303.c

zipfed.o: zipfed.cpp zipfed.hpp
	g++ -g -c zipfed.cpp

zipcode: zipcode.o zipfed.o 
	g++ -g zipcode.o zipfed.o -o zipcode

zipcode.o: zipcode.c zipcode.h zipfed.hpp
	g++ -g -c zipcode.c

docs:
	doxygen
	rsync -p -r /home/rboutayeb/cs2303_hws/cs2303_hw06/html/* /home/rboutayeb/public_html/cs2303_hw06/

clean:
	rm -r *.o fed2cs2303 output.csv
