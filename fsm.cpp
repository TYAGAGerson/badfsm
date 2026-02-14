#include "states.hh"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int GLOBAL_STATE;

vector<string> printout;
void switchState ();
bool quitloop = 0;


Main* state;

void switchState (Main* newst) {
    if (state) {
        delete state;
    }
    state = newst;
}

inline void setup(){
    fstream file ("messages.txt");
    string message;
    printout.push_back ("");
    while (getline (file, message)) {
        if (message == "") {
            if(printout.size()!=0){
                printout[printout.size () - 1].erase(printout[printout.size()-1].size()-1);
            }
            printout.push_back ("");
        } else {
            printout[printout.size () - 1] += message;
            printout[printout.size () - 1] += '\n';
            // cout << message << '\n';
        }
    }
    file.close();
}

int main () {
    setup();

    state = new home ();
    while (!quitloop) {
        state->handle ();
        state->process ();
    }
}
