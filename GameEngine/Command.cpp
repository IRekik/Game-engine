#include "Command.h"

Command::Command(string c, string e) {
    command = c;
    effect = e;
}

Command::Command(string c) {
    command = c;
}