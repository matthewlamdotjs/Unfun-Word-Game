#Matthew Lam
#Pengo: mlam
#Email: matthew.lam.93@icloud.com
#Filename: Makefile
#Assignment 4 - Unfun
#Description: Makefile for assignment 4
#Code status:

p4: main.o Dictionary.o Unfun.o
	g++ -o p4 main.o Dictionary.o Unfun.o

main.o: main.cpp Dictionary.h Unfun.h
	g++ -c main.cpp

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

Unfun.o: Unfun.cpp Unfun.h
	g++ -c Unfun.cpp

clean:
	rm -f p4 *.o *~
