#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

class point
{
public:
    double x, y;
    double getDistance(point p){
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }
};

bool Sort(point a, point b)
{
    return a.x < b.x;
}

double solve(int left, int right, point *arr)
{
    if(left >= right) return 10000;
    int mid = (left + right) / 2;
    double temp = min(solve(left, mid, arr), solve(mid + 1, right, arr));
    point line[10000];
    int n = 0;
    for(int i = mid; i >= left && arr[mid].x - arr[i].x < temp; i--){
        line[n++] = arr[i];
    }
    for(int i = mid + 1; i <= right && arr[i].x - arr[mid].x < temp; i++){
        line[n++] = arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            temp = min(temp, line[i].getDistance(line[j]));
        }
    }
    return temp;
}

int main()
{
    srand(time(NULL));
    point arr[5];
    for(int i = 0; i < 5; i++){
        arr[i].x = rand() % 100 + 1;
        arr[i].y = rand() % 100 + 1;
    }
    cout << "points" << endl;
    for(int i = 0; i < 5; i++){
        cout << arr[i].x << " " << arr[i].y << endl;
    }
    cout << "The shortest distance is: ";
    sort(arr, arr + 5, Sort);
    double shortest = solve(0, 4, arr);
    (shortest >= 10000) ? cout << "INFINITY" << endl : cout << fixed << setprecision(4) << shortest << endl;
    system("pause");
    return 0;
}
