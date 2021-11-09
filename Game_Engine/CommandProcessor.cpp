#include "CommandProcessor.h"

// tuple<string,string> CommandProcessor::readCommand() {
string CommandProcessor::readCommand() {
    string commandstr;
    cin >> commandstr;
    // string command = commandstr.substr(0,commandstr.find(' '));
    // string effect = commandstr.substr(command.length(), commandstr.length()-1);
    // return make_tuple(command, effect);
    return commandstr;
}

// void CommandProcessor::saveCommand(string c, string e) {
void CommandProcessor::saveCommand(string c) {
    Command cmd(c);
    // Command cmd(c, e);
    lc.push_back(cmd);
}

string CommandProcessor::getCommand() {
    // tuple <string, string> tp;
    string tp;
    tp = readCommand();
    saveCommand(tp);
    // saveCommand(get<0>(tp), get<1>(tp));
    return tp;
}

bool CommandProcessor::validate(State s, string cmd) {
    string c = cmd.substr(0,cmd.find(' '));
    if (c == "loadmap" && (s == START || s == MAPLOADED)) {
        cout << "Valid command. " << "\n";
        return true;
    }
    if (c == "validatemap" && s == MAPLOADED) {
        cout << "Valid command. " << "\n";
        return true;
    }
    if (c == "addplayer" && (s == MAPVALIDATED || s == PLAYERADDED)) {
        cout << "Valid command. " << "\n";
        return true;
    }
    if (c == "gamestart" && s == PLAYERADDED) {
        cout << "Valid command. " << "\n";
        return true;
    }
    if (c == "replay" && s == WIN) {
        cout << "Valid command. " << "\n";
        return true;
    }
    if (c == "quit" && s == WIN) {
        cout << "Valid command. " << "\n";
        return true;
    }
    cout << "Invalid input, please enter a valid option" << "\n";
    return false;
}