#include <iostream>
using namespace std;

/** author: 410821305 Michael Hsueh */

void init()
{
    cout << endl << "Welcome to Isozaki Coast renting system!" << endl << endl;
    cout << "   ========== renting menu ==========" << endl;
    cout << "       1   meters: 5    dollars" << endl;
    cout << "       100 meters: 1000 dollars" << endl;
    cout << "       200 meters: 1500 dollars" << endl;
    cout << "       300 meters: 2500 dollars" << endl;
    cout << "       400 meters: 4000 dollars" << endl;
    cout << "       500 meters: 6000 dollars" << endl;
    cout << "   ==================================" << endl;
    return;
}

void run()
{
    int n;
    cout << endl << "Please enter the length of the Isozaki Coast (meters): "; cin >> n; cout << endl;

    int rent_meter[6] = {1, 100, 200, 300, 400, 500};
    int rent_money[6] = {5, 1000, 1500, 2500, 4000, 6000};

    int max_profit[n + 1] = {0};
    for(int i = 0; i < 6; i++){
        for(int j = rent_meter[i]; j <= n; j++){
            max_profit[j] = max(max_profit[j], max_profit[ j - rent_meter[i] ] + rent_money[i]);
        }
    }

    cout << "The maximum profit is: " << max_profit[n] << " dollars." << endl;
}

int main()
{
    init();
    run();
    return 0;
}
