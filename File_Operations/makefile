#Makefile for Assignment 2, Problem 2
SRC = Parser.cpp test_Parser.cpp Label.cpp

all: Parser

Parser: ${SRC}
	g++ -std=gnu++14  ${SRC} -o Parser

debug: ${SRC}
	echo << compiling with debugging info
	g++ -std=gnu++14 -ggdb  ${SRC} -o Parser
	echo << starting gdb
	gdb Parser

clean:
	rm -f  Parser
