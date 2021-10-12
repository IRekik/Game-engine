#include <iostream>
#include <map>

using namespace std;

enum GameState {startup,play};
enum StartupManagerState {start, mapLoaded,mapValidated, playersAdded, finishSMS};
enum PlayManagerState {assignReinforcement, issueOrders, executeOrders, win, finishPMS};

const map <GameState, string> gsmap = {{startup, "startup"}, {play, "play"}};
const map <StartupManagerState, string> smsmap = {{start, "start"}, {mapLoaded, "mapLoaded"}, {mapValidated, "mapValidated"}, {playersAdded, "playersAdded"}, {finishSMS, "finishSMS"}};
const map <PlayManagerState, string> pmsmap = {{assignReinforcement,"assignReinforcement"},{issueOrders, "issueOrders"}, {executeOrders, "executeOrders"}, {win, "win"}, {finishPMS, "finishPMS"}};

GameState gs;

bool isGameOver = false;

class StartupManager {
    StartupManagerState sms;
    public:
        void printSMS() {
            cout << "The game is in " << gsmap.at(gs) << " state at the " << smsmap.at(sms) << " sub-state." << "\n";
        }
        void setSms(StartupManagerState s) {
            sms = s;
        }
        void init () {
            cout << "\n";
            gs = startup;
            setSms(start);
            printSMS();
            cout << "Please enter an option" << "\n";
            string * input = new string();
            cin >> *input;
            while (true) {
                if (*input == "loadmap") {
                    cout << "Loading the map.\n";
                    mapLoad();
                    break;
                }
                else {
                    cout << "Invalid input, please enter a valid option" << "\n";
                    cin >> *input;
                }
            }
        }
        void mapLoad() {
            cout << "\n";
            // load map
            setSms(mapLoaded);
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
        }
        void validateMap() {
            cout << "\n";
            // validate map
            setSms(mapValidated);
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
        }
        void addPlayers() {
            cout << "\n";
            // load map
            setSms(playersAdded);
            printSMS();
            cout << "Please enter an option" << "\n";
            string *input = new string ();
            cin >> *input;
            while (true) {
                if (*input == "addplayer") {
                    cout << "Adding player." << "\n";
                    // load map
                    printSMS();
                    cout << "Please enter an option" << "\n";
                    cin >> *input;

                }
                else if (*input == "assigncountries") {
                    cout << "Assigning countries" << "\n";
                    break;
                }
                else {
                    cout << "Invalid input, please enter a valid option" << "\n";
                    cin >> *input;
                }
            }
            assignCountries();
        }
        void assignCountries() {
            cout << "\n";
            // assign countries
            setSms(finishSMS);
            gs = play;
            cout << "End of startup phase." << "\n\n\n";
            cout << "Thank you for your patience. The game shall now startup!\n";
        }

};

class PlayManager {
    PlayManagerState pms;
    public:
        void printPMS() {
            cout << "The game is in " << gsmap.at(gs) << " state at the " << pmsmap.at(pms) << " sub-state." << "\n";
        }
        void setPms(PlayManagerState p) {
            pms = p;
        }
        void init () {
            setPms(assignReinforcement);
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
        }
        void issueOrder(){
            cout << "\n";
            // issue orders
            setPms(issueOrders);
            printPMS();
            cout << "Please enter an option" << "\n";
            string input;
            cin >> input;
            while (true) {
                if (input == "issueorder") {
                    cout << "Issuing order." << "\n";
                    // issue orders
                    printPMS();
                    cout << "Please enter an option" << "\n";
                    cin >> input;
                }
                else if (input == "endissueorders") {
                    cout << "Ending issue orders." << "\n";
                    endIssueOrders();
                    break;
                }
                else {
                    cout << "Invalid input, please enter a valid option" << "\n";
                    cin >> input;
                }
            }
        }
        void endIssueOrders() {
            cout << "\n";
            // end issue order
            setPms(executeOrders);
            printPMS();
            cout << "Please enter an option" << "\n";
            string input;
            cin >> input;
            while (true) {
                if (input == "execorder") {
                    cout << "Executing order." << "\n";
                    exeOrder();
                    break;
                }
                else if (input == "endexecorders") {
                    cout << "Ending executing orders." << "\n";
                    endExeOrders();
                    break;
                }
                else if (input == "win") {
                    cout << "THIS IS A WIN!" << "\n";
                    wins();
                    break;
                }
                else {
                    cout << "Invalid input, please enter a valid option" << "\n";
                    cin >> input;
                }
            }
        }
        void exeOrder() {
            cout << "\n";
            // execute order
            setPms(executeOrders);
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
        }
        void endExeOrders(){
            cout << "\n";
            // end execute orders
            setPms(assignReinforcement);
            init();
        }
        void wins() {
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
            printPMS();
            cout << "Please enter an option" << "\n";
            string input;
            cin >> input;
            while (true) {
                if (input == "end") {
                    cout << "Ending the game. See you soon!" << "\n";
                    end();
                    break;
                }
                else if (input == "play") {
                    cout << "Want to replay? Restarting the game!" << "\n";
                    gs = startup;
                    play();
                    break;
                }
                else {
                    cout << "Invalid input, please enter a valid option" << "\n";
                    cin >> input;
                }
            }
        }
        void play() {
            cout << "Game is now restarting. Please wait." << "\n\n";
        }
        void end() {
            isGameOver = true;
        }

};

int main() {
    while (isGameOver == false) {
        cout << "Welcome to Warzone!" << "\n";
        cout << "The game will now startup setting up, please wait." << "\n" << "\n";
        StartupManager sm;
        sm.init();
        PlayManager pm;
        pm.init();
    }
    return 0;
}
