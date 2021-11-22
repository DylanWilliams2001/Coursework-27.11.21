DataParser:main.o format.o meminfo.o stat.o  uptime.o
	g++ -Wall -o  DataParser  main.o format.o meminfo.o stat.o  uptime.o  -I.

main.o: main.cpp
	g++ -o main.o -c main.cpp

meminfo.o: meminfo.cpp
	g++ -o meminfo.o -c meminfo.cpp

stat.o: stat.cpp
	g++ -o stat.o -c stat.cpp

uptime.o: uptime.cpp
	g++ -o uptime.o -c uptime.cpp

format.o: format.cpp
	g++ -o format.o -c format.cpp

clean.o:
	rm -f DataParser
	rm -f *.o
