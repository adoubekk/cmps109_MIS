#havent tested this makefile..
SRC = Exception.cpp ArithmeticException.cpp testException.cpp

all: TestException

TestException: ${SRC}
	g++  ${SRC} -o TestException

clean:
	rm *Exception*

