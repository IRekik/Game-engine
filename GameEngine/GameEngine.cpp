#include "GameEngine.h"

using namespace std;

const map <GameState, string> gsmap = {{startup, "startup"}, {play, "play"}};
const map <StartupManagerState, string> smsmap = {{start, "start"}, {mapLoaded, "mapLoaded"}, {mapValidated, "mapValidated"}, {playersAdded, "playersAdded"}, {finishSMS, "finishSMS"}};
const map <PlayManagerState, string> pmsmap = {{assignReinforcement,"assignReinforcement"},{issueOrders, "issueOrders"}, {executeOrders, "executeOrders"}, {win, "win"}, {finishPMS, "finishPMS"}};

GameState gs;

State s;

CommandProcessor cp;

bool isGameOver = false;

void StartupManager::printSMS() {
    cout << "The game is in " << gsmap.at(gs) << " state at the " << smsmap.at(sms) << " sub-state." << "\n";
}
void StartupManager::setSms(StartupManagerState s) {
    sms = s;
}
void StartupManager::init () {
    cout << "\n";
    gs = startup;
    setSms(start);
    s = START;
    printSMS();
    cout << "Please enter an option" << "\n";
    string input = cp.getCommand();
    while (!cp.validate(s, input)) {
        input = cp.getCommand();
    }
    cout << "Loading the map.\n";
    mapLoad();
}
void StartupManager::mapLoad() {
    cout << "\n";
    // load map
    setSms(mapLoaded);
    s = MAPLOADED;
    printSMS();
    cout << "Please enter an option" << "\n";
    string * input = new string ();
    cin >> *input;
    while (true) {
        if (*input == "loadmap") {
            cout << "Loading the map.\n";
            printSMS();
            cout << "Please enter an option" << "\n";
            cin >> *input;
            // load map
        }
        else if (*input == "validatemap") {
            cout << "Validating the map." << "\n";
            validateMap();
            break;
        }
        else {
            cout << "Invalid input, please enter a valid option" << "\n";
            cin >> *input;
        }
    }
    delete input;
}
void StartupManager::validateMap() {
    cout << "\n";
    // validate map
    setSms(mapValidated);
    s = MAPVALIDATED;
    printSMS();
    cout << "Please enter an option" << "\n";
    string * input= new string();
    cin >> *input;
    while (true) {
        if (*input == "addplayer") {
            cout << "Adding player." << "\n";
            addPlayers();
            break;
        }
        else {
            cout << "Invalid input, please enter a valid option" << "\n";
            cin >> *input;
        }
    }
    delete input;
}
void StartupManager::addPlayers() {
    cout << "\n";
    // load map
    setSms(playersAdded);
    s = PLAYERADDED;
    printSMS();
    cout << "Please enter an option" << "\n";
    string *input = new string ();
    cin >> *input;
    while (true) {
        if (*input == "addplayer") {
            cout << "Adding player." << "\n";
            // add player
            printSMS();
            cout << "Please enter an option" << "\n";
            cin >> *input;
        }
        else if (*input == "assigncountries") {
            cout << "Assigning countries" << "\n";
            assignCountries();
            break;
        }
        else {
            cout << "Invalid input, please enter a valid option" << "\n";
            cin >> *input;
        }
    }
    delete input;
}
void StartupManager::assignCountries() {
    cout << "\n";
    // assign countries
    setSms(finishSMS);
    gs = play;
    cout << "End of startup phase." << "\n\n\n";
    cout << "Thank you for your patience. The game shall now startup!\n";
}

void PlayManager::printPMS() {
    cout << "The game is in " << gsmap.at(gs) << " state at the " << pmsmap.at(pms) << " sub-state." << "\n";
}
void PlayManager::setPms(PlayManagerState p) {
    pms = p;
}
void PlayManager::init () {
    setPms(assignReinforcement);
    s = ASSIGNREINFORCEMENT;
    printPMS();
    cout << "Please enter an option" << "\n";
    string *input = new string ();
    cin >> *input;
    while (true) {
        if (*input == "issueorder") {
            cout << "Issuing order." << "\n";
            issueOrder();
            break;
        }
        else {
            cout << "Invalid input, please enter a valid option" << "\n";
            cin >> *input;
        }
    }
    delete input;
}
void PlayManager::issueOrder(){
    cout << "\n";
    // issue orders
    setPms(issueOrders);
    s = ISSUEORDER;
    printPMS();
    cout << "Please enter an option" << "\n";
    string * input = new string ();
    cin >> *input;
    while (true) {
        if (*input == "issueorder") {
            cout << "Issuing order." << "\n";
            // issue orders
            printPMS();
            cout << "Please enter an option" << "\n";
            cin >> *input;
        }
        else if (*input == "endissueorders") {
            cout << "Ending issue orders." << "\n";
            endIssueOrders();
            break;
        }
        else {
            cout << "Invalid input, please enter a valid option" << "\n";
            cin >> *input;
        }
    }
    delete input;
}
void PlayManager::endIssueOrders() {
    cout << "\n";
    // end issue order
    setPms(executeOrders);
    s = EXECUTEORDERS;
    printPMS();
    cout << "Please enter an option" << "\n";
    string * input = new string ();
    cin >> *input;
    while (true) {
        if (*input == "execorder") {
            cout << "Executing order." << "\n";
            exeOrder();
            break;
        }
        else if (*input == "endexecorders") {
            cout << "Ending executing orders." << "\n";
            endExeOrders();
            break;
        }
        else if (*input == "win") {
            cout << "THIS IS A WIN!" << "\n";
            wins();
            break;
        }
        else {
            cout << "Invalid input, please enter a valid option" << "\n";
            cin >> *input;
        }
    }
    delete input;
}
void PlayManager::exeOrder() {
    cout << "\n";
    // execute order
    setPms(executeOrders);
    s = EXECUTEORDERS;
    printPMS();
    cout << "Please enter an option" << "\n";
    string * input = new string ();
    cin >> * input;
    while (true) {
        if (*input == "execorder") {
            cout << "Executing order." << "\n";
            // execute order
            printPMS();
            cout << "Please enter an option" << "\n";
            cin >> *input;
        }
        else if (*input == "endexecorders") {
            cout << "Ending executing orders." << "\n";
            endExeOrders();
            break;
        }
        else if (*input == "win") {
            cout << "THIS IS A WIN!" << "\n";
            wins();
            break;
        }
        else {
            cout << "Invalid input, please enter a valid option" << "\n";
            cin >> *input;
        }
    }
    delete input;
}
void PlayManager::endExeOrders(){
    cout << "\n";
    // end execute orders
    setPms(assignReinforcement);
    s = ASSIGNREINFORCEMENT;
    init();
}
void PlayManager::wins() {
    cout << "\n";
    cout <<
    "            '._==_==_=_.'\n"
    "            .-\\:      /-.\n"
    "           | (|:.     |) |\n"
    "            '-|:.     |-'\n"
    "              \\::.    /\n"
    "               '::. .'\n"
    "                 ) (\n"
    "               _.' '._\n"
    "              `\"\"\"\"\"\"\"`\n";
    setPms(win);
    s = WIN;
    printPMS();
    cout << "Please enter an option" << "\n";
    string * input = new string ();
    cin >> *input;
    while (true) {
        if (*input == "end") {
            cout << "Ending the game. See you soon!" << "\n";
            end();
            break;
        }
        else if (*input == "play") {
            cout << "Want to replay? Restarting the game!" << "\n";
            gs = startup;
            play();
            break;
        }
        else {
            cout << "Invalid input, please enter a valid option" << "\n";
            cin >> *input;
        }
    }
    delete input;
}
void PlayManager::play() {
    cout << "Game is now restarting. Please wait." << "\n\n";
}
void PlayManager::end() {
    isGameOver = true;
}


