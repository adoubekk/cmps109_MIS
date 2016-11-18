#ifndef THREAD_BEGIN_H
#define THREAD_BEGIN_H

#include "../Type_Classes/Type.h"
#include "../MIS/Keyword.h"
#include "../File_Operations/Parser.h"
#include <vector>
#include <map>
#include <stdlib.h>
#include <thread>
#include <mutex>


using namespace std;

class Thread_Begin{
private:
	vector<string> instructions; 
	map<string, Type *> * Mis_Vars;

	map<string, Keyword *> Keyword_Factory;

	thread FactoryThread;
public:
	


    void execute(); // instantiate the thread

    void initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

    Thread_Begin* clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser);

    void runThread(map<string, Keyword*>& Keyword_Factory,map<string, Type*>& variables,mutex& m,int& threadCount, vector<thread>& threads);

};




#endif