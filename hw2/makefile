main: main.o student.o
	g++ -o main main.o student.o
main.o: main.cpp student.h
	g++ -c main.cpp -std=c++11 -O2 -Wall
student.o: student.cpp student.h
	g++ -c student.cpp -std=c++11 -O2 -Wall