#ifndef GAME_ENGINE_COMMAND_H
#define GAME_ENGINE_COMMAND_H
#include <iostream>

using namespace std;

class Command {
    public:
        Command(string c, string e);
        Command(string c);
    private:
        string command;
        string effect;
        void saveEffect(string c, string e);
};


#endif //GAME_ENGINE_COMMAND_H
