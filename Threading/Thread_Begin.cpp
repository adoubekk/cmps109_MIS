#include "Thread_Begin.h"



void Thread_Begin::execute(){} // instantiate the thread

void runThread(map<string, Type*>& variables){} // thread function

void Thread_Begin::initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){

	while(MIS_Parser->hasNextLine()){
		int lineSize = 0;
        args = MIS_Parser->getNextLine();
        if(args[0] = "THREAD_END"){
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

Keyword* Thread_Begin::clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser){
	Thread_Begin* newThread = new Thread_Begin();
	newThread->initialize(args, variables, MIS_Parser);
	return newThread;
}