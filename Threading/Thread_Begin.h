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

	//thread Factory_Thread;
public:
	

    void initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser, map<string, Keyword*>& Keyword_Factory,mutex& m, vector<thread>& threads);

    Thread_Begin* clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser, map<string, Keyword*>& Keyword_Factory,mutex& m, vector<thread>& threads);

   // void runThread(map<string, Keyword*>& Keyword_Factory,map<string, Type*>& variables,mutex& m, vector<thread>& threads);

};




#endif