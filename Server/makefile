SRCS =  Server.cpp ../TCP/sources/TCPServerSocket.cpp ../TCP/sources/TCPSocket.cpp  ../File_Operations/*.cpp ../File_Operations/Jump/*.cpp ../Arithmetic_Operations/*.cpp ../Threading/Thread_Begin.cpp ../Exceptions_Draft/*.cpp ../Type_Classes/*.cpp ../MIS/MIS.cpp ../MIS/Out.cpp ../MIS/Sleep.cpp
SRCS2 = ../TCP/sources/TCPServerSocket.cpp ../TCP/sources/TCPSocket.cpp Server.cpp
SRCO = *.o
EXE = Server

all: ${EXE}

${EXE}: ${SRCO}
	g++ -std=gnu++14 ${SRCO} -o ${EXE}

${SRCO}: ${SRCS}
	g++ -std=gnu++14 ${SRCS} -c

clean:
	rm -f Server *.o
