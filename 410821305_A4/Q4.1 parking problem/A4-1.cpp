#include <iostream>
#define n 10
using namespace std;

/** Author: 410821305 Michael Hsueh **/

/**
*   park array: stores the parking space, 1 if there are a parking space.
*   cars array: stores the car's location, 1 if there is a car.
*/
bool park[n] = {0}, cars[n] = {0};

void input()
{
    int count_park = 0, count_cars = 0;
    cout << "please input where are the parking spaces:" << endl;
    for(int i = 0; i < n; i++){
        cin >> park[i];
        if(park[i]){
            count_park++;
        }
    }
    cout << endl;
    cout << "please input where are the cars:" << endl;
    for(int i = 0; i < n; i++){
        cin >> cars[i];
        if(cars[i]){
            count_cars++;
        }
    }
    cout << endl;
    if(count_cars > count_park){
        cout << "Wrong input! The count of the cars shouldn't be more than the count of the parking spaces!" << endl;
        cout << "Please try again." << endl;
        cout << "-----------------------------------------------------------" << endl << endl;
        input();
    }
    if(count_cars == 0){
        cout << "answer: 0" << endl;
        cout << "-----------------------------------------------------------" << endl << endl;
        input();
    }
}

void run()
{
    /**
    *   what is in the "shortest" array
    *   row1: destination parking space
    *   row2: the shortest length to the parking space
    */
    int shortest[2][n];
    for(int i = 0; i < n; i++){
        shortest[0][i] = -1;
        shortest[1][i] = -1;
    }

    /** initialize the shortest array */
    for(int i = 0; i < n; i++){
        if(cars[i]){
            int temp = n;
            for(int j = 0; j < n; j++){
                if(park[j] && temp > abs(i - j)){
                    shortest[0][i] = j;
                    temp = abs(i - j);
                }
            }
            shortest[1][i] = temp;
        }
    }

    int answer = 0;
    bool flag = 1;

    /**
    *   while loop
    *   choose the shortest
    *   put the car into the parking lot, while refresh the array: cars, park and shortest
    *   refresh the list
    *   redo until all of the cars are in the parking space
    */

    while(flag){
        int shortest_length = n, index = -1;
        for(int i = 0; i < n; i++){
            if(shortest_length > shortest[1][i] && shortest[1][i] != -1){
                shortest_length = shortest[1][i];
                index = i;
            }
        }

        answer += shortest_length;
        park[ shortest[0][index] ] = 0;
        cars[index] = 0;
        shortest[0][index] = -1;
        shortest[1][index] = -1;

        for(int i = 0; i < n; i++){
            if(cars[i]){
                int temp = n;
                for(int j = 0; j < n; j++){
                    if(park[j] && temp > abs(i - j)){
                        shortest[0][i] = j;
                        temp = abs(i - j);
                    }
                }
                shortest[1][i] = temp;
            }
        }

        /** check if there are cars that are not in the parking space or not*/
        for(int i = 0; i < n; i++){
            if(shortest[0][i] != -1){
                flag = 1;
                break;
            }
            flag = 0;
        }
    }
    cout << "answer: " << answer << endl;
    cout << "-----------------------------------------------------------" << endl << endl;
}

int main()
{
    while(true){
        input();
        run();
    }
    return 0;
}
