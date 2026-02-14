#include "states.hh"
#include "settings.hh"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
extern std::vector<std::string> printout;
extern bool quitloop;
void home::handle () {
    bool answered = 0;
    cout << printout[0];
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
        switch (gotonum) {
        case 4:
            answered = 1;
            quitloop = 1;
            break;
        case 1: answered = 1; break;
        case 2: answered = 1; break;
        case 3: answered = 1; break;
        default: cout << printout[0]; break;
        }
        if (gotonum == 4) {
            continue;


        } else if (gotonum == 1) {
            switchState (new gameplay ());

        } else if (gotonum == 3) {
            switchState (new settings ());
        } else if (gotonum == 2) {
            switchState (new credits ());
        }
    }
}


void home::process () {
}


void gameplay::handle () {
    for(int i=0;i<1000000;i++){}
    if(paused!=1){
    timeElapsed++;}
    if (paused==0&&timeElapsed % globalSettings[globalSettings::postPauseTime] == 0) {
        paused = 1;
    }
}
void gameplay::process () {

    if (!paused) {
        if(timeElapsed%(100/globalSettings[globalSettings::speed])==0)
        cout << printout[timeElapsed % 2 ? 3 : 4] << endl;
    } else {
        if (paused == 1) {
            cout << printout[7];
            string ans;
            getline (cin, ans);
            if (ans == "1") {
                paused = 0;
            } else {
                if (ans == "0") {
                    switchState (new home ());
                }
            }
        } else if (paused == 3) {
            cout << printout[1] << endl;
            paused = 2;
        } else if (paused == 2) {
            if (timeElapsed % 200 == 0) {
                cout << (10 - timeElapsed / 200) << endl;
                if (timeElapsed == 2000) {
                    timeElapsed=0;
                    paused = 0;
                }
            }
        }
    }
}
void credits::handle () {
}
void credits::process () {
    cout << printout[2];
    string ans;
    getline (cin, ans);
    if (ans == "0") {
        switchState (new home ());
    }
}
