#include "Thread_Begin.h"
#include <iostream>
using namespace std;

//ruuThread -- Thread Function
// iterate through instructions, locking the variables map each time
static void runThread(map<string, Keyword*>& Keyword_Factory,map<string, Threading_Keyword*>& Thread_Factory,map<string, Type*>& variables,mutex& m, vector<thread*>& threads, Parser* MIS_Parser, vector<string>& instructions, map<string, int>& Locked_Vars, int thread_id){

  //cout << "in run" << endl;
  vector<string> tempArgs;
  int size = instructions.size();

  //cout << "whats in instructions: " << endl; TESTING PURPOSES

  Keyword* KeywordObj;
  Threading_Keyword* ThreadObj;

  for(int i = 0; i < size; i++){


    //cout << i << "  " << instructions[i] << endl; TESTING PURPOSES 
    int locked_index;
    locked_index = Locked_Vars[instructions[i]];
    if(locked_index != 0){
      if(locked_index != thread_id){ // if this thread doesn't have the lock
        while(Locked_Vars[instructions[i]] != 0){
          // do nothing, wait
        }
      }
    }
    //m.lock();

    if(instructions[i] == "END_INSTRUCTION"){
     // cout << "tempArgs[0] " << tempArgs[0] << endl;
      if (tempArgs[0] == "VAR"){ 
            KeywordObj = Keyword_Factory[tempArgs[2]];
         } else {
            KeywordObj = Keyword_Factory[tempArgs[0]];
            ThreadObj = Thread_Factory[tempArgs[0]];
         }

         if(KeywordObj != NULL){
            try{
              
               KeywordObj = KeywordObj->clone(tempArgs, variables, MIS_Parser);
               KeywordObj->execute();
               
               
            }
            catch(exception& e){
              // file << e.what() << endl;
            }
         }if(ThreadObj != NULL && KeywordObj == NULL){ 
               cout << "keyObj is NULL, threadObj not NUll" << endl;  
               //ThreadObj = Thread_Factory[args[0]];
              /* if(args[0] == "THREAD_BEGIN"){     NO NESTED THREADING
                  Thread_id++; // thread counter is used to ID the threads
               }*/
            
               ThreadObj = ThreadObj->clone(tempArgs, variables, MIS_Parser, Keyword_Factory, Thread_Factory, m, threads, thread_id, Locked_Vars);
               ThreadObj->execute();
               

         } else {
           // file << "Unidentified Keyword" << endl;
         }
         tempArgs.clear();
         continue; // go to next 
    }
    
    tempArgs.push_back(instructions[i]);
    //m.unlock();

  }
} // thread function; pass references to the data and mutex, don't lock the mutex before looping.


// Collect all instructions until THREAD_END
void Thread_Begin::initialize(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser, map<string, Keyword*>& Keyword_Factory,map<string, Threading_Keyword*>& Thread_Factory,mutex& m, vector<thread*>& threads, int thread_id, map<string, int>& Locked_Vars){
  this->thread_id = thread_id;
  //cout << "in initialize" << endl; TESTING PURPOSES
	while(MIS_Parser->hasNextLine()){
		int lineSize = 0;
        args = MIS_Parser->getNextLine();
        if(args[0] == "THREAD_END"){ 
          //cout << "found end" << endl;
        	break;
        }
        else{
        	lineSize = args.size();
        	for(int i = 0; i < lineSize ; i++){
            //cout << "arg " << i<< args[i] << endl; TESING PURPOSES 
        		instructions.push_back(args[i]); // push back instructions
        	}
        	instructions.push_back("END_INSTRUCTION");

        }

         
      }
      thread Factory_Thread(runThread, ref(Keyword_Factory), ref(Thread_Factory), ref(variables), ref(m) , ref(threads), ref(MIS_Parser), ref(instructions), ref(Locked_Vars), ref(this->thread_id)); // start the factory work on the chunk of code
      threads.push_back(&Factory_Thread); // will be used for barrier
      Factory_Thread.join();
      

}

// Pass in regular data along with threading variables/structures
Threading_Keyword* Thread_Begin::clone(vector<string> args, map<string, Type*>& variables, Parser* MIS_Parser, map<string, Keyword*>& Keyword_Factory,map<string, Threading_Keyword*>& Thread_Factory,mutex& m, vector<thread*>& threads, int thread_id, map<string, int>& Locked_Vars){
	Threading_Keyword* newThread = new Thread_Begin();
	newThread->initialize(args, variables, MIS_Parser, Keyword_Factory, Thread_Factory, m, threads, thread_id, Locked_Vars);
	return newThread;
}

void Thread_Begin::execute(){}