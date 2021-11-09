#ifndef GAME_ENGINE_COMMANDPROCESSOR_H
#define GAME_ENGINE_COMMANDPROCESSOR_H
#include <iostream>
#include <list>
#include <tuple>
#include "Command.h"
#include "GameEngine.h"

using namespace std;

class CommandProcessor{
    public:
        CommandProcessor();
        string getCommand();
        list <Command> lc;
        bool validate(State s, string cmd);
    private:
        // tuple<string,string> readCommand();
        string readCommand();
        // void saveCommand(string c, string e);
        void saveCommand(string c);
};


#endif //GAME_ENGINE_COMMANDPROCESSOR_H
