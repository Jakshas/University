make:
	g++  -Wall -Werror -c traceroute.cpp helping_functions.cpp send.cpp recive.cpp
	g++ -o traceroute.out traceroute.o helping_functions.o send.o recive.o
clean:
	rm -f *.o

distclean:
	rm -f *.o *.out