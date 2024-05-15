all: testIPQ 


testIPQ: testIPQ.o 
	g++ -Wall -o testIPQ testIPQ.o



testOSULL.o: testIPQ.cpp IPQ.h
	g++ -Wall -o testIPQ.o -c testIPQ.cpp


clean:
	rm -f testIPQ  *.o
