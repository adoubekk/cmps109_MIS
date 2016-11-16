#Makefile for Assignment 2, Problem 2
SRC = main.cpp File_Operations/*.cpp File_Operations/Jump/*.cpp Arithmetic_Operations/*.cpp Exceptions_Draft/*.cpp Type_Classes/*.cpp MIS/MIS.cpp MIS/Out.cpp MIS/Sleep.cpp

all: MIS_x

MIS_x: ${SRC}
	g++ -std=gnu++14 ${SRC} -o MIS_x

debug: ${SRC}
	echo << compiling with debugging info
	g++ -std=gnu++14 -ggdb  ${SRC} -o MIS_x
	echo << starting gdb
	gdb MIS_x

clean:
	rm -f MIS_x MIS.err
