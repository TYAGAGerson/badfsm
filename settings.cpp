#include "settings.hh"
#include "states.hh"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
std::vector<int> globalSettings = { 100, 1000 };
extern std::vector<std::string> printout;
void settings::handle () {
    int gotonum = 0;

    bool answered = 0;

    cout << printout[5] << globalSettings[0] << "%\n"
         << printout[6] << globalSettings[1] << " ticks";
    if (mode) {
        cout << "\ngo back(0) or set (" << mode << ") to:";
    } else
        cout << "\ngo back     (0)\nchoose what properties to change:";

    while (!answered) {

        string ans;
        getline (cin, ans);
        try {
            int val = stoi (ans);
            gotonum = val;
        } catch (invalid_argument& e) {
            cout << "invalid argument, try again:";
            continue;
        } catch (out_of_range& e) {
            cout << "out of range, try again:";
            continue;
        }
        if (mode) {
            if (gotonum > 0) {
                globalSettings[mode - 1] = gotonum;
            }


            if (gotonum > -1) {
                answered = 1;
                mode     = 0;
            } else {
                cout << "out of range, try again:";
            }


        } else {
            if (gotonum == 0) {
                answered = 1;
                switchState (new home ());
            } else {
                if (gotonum <= globalSettings.size ()) {
                    mode     = gotonum;
                    answered = 1;
                } else
                    cout << "out of range, try again:";
            }
        }
    }
}


void settings::process () {
}