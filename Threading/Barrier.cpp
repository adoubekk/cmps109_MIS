#include "Barrier.h"

using namespace std;

// join all threads
void Barrier::initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser, map<string, Keyword*>& Keyword_Factory,map<string, Threading_Keyword*>& Thread_Factory,mutex& m, vector<thread*>& threads, int thread_id,map<string, int>& Locked_Vars){

	for(int i = 0; i < threads.size() ; i++){
		thread* temp = threads[i];
		temp->join();
	}

}

Threading_Keyword* Barrier::clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser, map<string, Keyword*>& Keyword_Factory,map<string, Threading_Keyword*>& Thread_Factory,mutex& m, vector<thread*>& threads, int thread_id,map<string, int>& Locked_Vars){
	Threading_Keyword* myBarrier = new Barrier();
    myBarrier->initialize(args, variables, MIS_Parser, Keyword_Factory, Thread_Factory, m, threads, thread_id, Locked_Vars);
	return myBarrier;

}

void Barrier::execute(){}