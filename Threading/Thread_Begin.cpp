#include "Thread_Begin.h"



void Thread_Begin::execute(){} // instantiate the thread

void Thread_Begin::runThread(map<string, Keyword*>& Keyword_Factory,map<string, Type*>& variables,mutex& m,int& count, vector<thread>& threads){} // thread function; pass references to the data and mutex, don't lock the mutex before looping.

void Thread_Begin::initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){



	while(MIS_Parser->hasNextLine()){
		int lineSize = 0;
        args = MIS_Parser->getNextLine();
        if(args[0] == "THREAD_END"){
        	break;
        }
        else{
        	lineSize = args.size();
        	for(int i = 0; i < lineSize ; i++){
        		instructions.push_back(args[i]); // push back instructions
        	}
        	instructions.push_back("END_INSTRUCTION");

        }

         
      }
      //Maybe leave execute blank (instantiate thread here) so we can keep the variables reference
      // std:: thread t(runThread, variables)
      //  t.join()

}

Thread_Begin* Thread_Begin::clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){
	Thread_Begin* newThread = new Thread_Begin();
	newThread->initialize(args, variables, MIS_Parser);
	return newThread;
}