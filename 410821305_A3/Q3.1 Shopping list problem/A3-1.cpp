#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

/** author: 410821305 Michael Hsueh */

int willing[7], price[7] = {20, 25, 30, 35, 50, 60, 80};
int counting = 0, budget;
string drinks[7] = {"Green tea ", "Black tea ", "Sprite    ", "Coca Cola ", "Milk tea  ", "Bubble tea", "Beer      "};

void init()
{
    cout << endl << "      Welcome to Tsuen's drink store!" << endl << endl;
    cout << "===========================================" << endl;
    cout << "          The drinks we sell are:" << endl << endl;
    cout << "             .Green tea  : 20$" << endl;
    cout << "             .Black tea  : 25$" << endl;
    cout << "             .Sprite     : 30$" << endl;
    cout << "             .Coca Cola  : 35$" << endl;
    cout << "             .Milk tea   : 50$" << endl;
    cout << "             .Bubble tea : 60$" << endl;
    cout << "             .Beer       : 80$" << endl;
    cout << "===========================================" << endl << endl;
    return;
}

void input_phase_run()
{
    cout << "Please enter how happy you are with getting drinks.(0 to 100)" << endl;
    while(counting < 7){
        cout << "For the drink " << drinks[counting] << ": ";
        int points;
        cin >> points;
        if(points < 0 || points > 100){
            cout << "Incorrect input! Please enter a number that is between 0 to 100." << endl;
        }
        else{
            willing[counting++] = points;
        }
    }
    cout << endl << "Please tell us your budget!" << endl;
    cout << "My budget is: "; cin >> budget;

    /** dynamic programming **/
    int max_happiness[budget + 1] = {0};
    for(int i = 0; i < 7; i++){
        for(int j = budget; j >= 1; j--){
            if(j >= price[i]){
                max_happiness[j] = max(max_happiness[j], max_happiness[ j - price[i] ] + willing[i]);
            }
        }
    }

    cout << "Happiness: " << max_happiness[budget] << endl << endl;
    cout << "Enjoy your drink!" << endl;
}

int main()
{
    init();
    input_phase_run();
    return 0;
}
