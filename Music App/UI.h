/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   

            Program:  Tuner Pro          
            Authors:                              
    
              (c) Syed Arsal Abbas
                  100835968

              (c) Muhmammad Junaid Farooqui
                  100912649
                          
            Due Date:     5-Dec-2017
                                                     */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef UI_H
#define UI_H

#include <string>
#include <sstream>

using namespace std;

#include "command.h"

/*
This class represents the command line interface
It runs the UI on behalf of a MyTunes owner app.
It collects keyboard input commands from user
and provides a location for application
commands to write output.
*/
class MyTunes; //forward declaration needed

class UI{
  public:
    UI(MyTunes * anOwner);
    void run();
    void printOutput(string message);

  private:
     MyTunes * owner; //owner app
     enum LogMode {OFF, COMMAND, OUTPUT, BOTH};
     LogMode logging;
     vector<string> logs;
     void promptForStr(string, string&);
     void pause();
     void printError(string err);
     void printMessage(string message);
     void executeCommand(Command aCommand);
     void executeDevCommand(Command aCommand);
     void executeUIREAD(Command cmd);
     void executeUILOG(Command cmd);
     void executeUIHELP(Command cmd);  
};

#endif