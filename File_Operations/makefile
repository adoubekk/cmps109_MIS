#Makefile for Assignment 2, Problem 2
SRC = test_Parser.cpp Parser.cpp Jump/*.cpp Label.cpp ../Type_Classes/Numeric.cpp ../Type_Classes/Real.cpp
OBJS = ${patsubst %.cpp, %.o, ${SRC}}

all: Parser

Parser: ${SRC}
	g++ -std=gnu++14 ${SRC} -o Parser

debug: ${SRC}
	echo << compiling with debugging info
	g++ -std=gnu++14 -ggdb  ${SRCS} -o Parser
	echo << starting gdb
	gdb Parser

clean:
	rm -f  Parser
