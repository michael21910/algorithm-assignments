#include <iostream>
#include <cstdlib>
using namespace std;

int maximumSubarray(int *arr, int n, int left, int right)
{
    int mid = (left + right) / 2;
    if(left == right){
        return arr[left];
    }
    int leftSum = maximumSubarray(arr, n, left, mid);
    int rightSum = maximumSubarray(arr, n, mid + 1, right);
    int temp = 0, crossingLeft = 0, crossingRight = 0;
    for(int i = mid + 1; i <= right; i++){
        temp += arr[i];
        if(crossingRight < temp){
           crossingRight  = temp;
        }
    }
    temp = 0;
    for(int i = mid; i >= left; i--){
        temp += arr[i];
        if(crossingLeft < temp){
            crossingLeft = temp;
        }
    }
    int crossing = crossingLeft + crossingRight;
    return max(crossing, max(leftSum, rightSum));
}

int burteforce(int *arr, int n)
{
    int maximum = 0;
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = i + 1; j < n; j++){
            temp += arr[j];
        }
        if(maximum < temp){
            maximum = temp;
        }
    }
    return maximum;
}

int main()
{
    int arr[7] = {-1, 2, 4, -3, 0, 9, 7};
    cout << maximumSubarray(arr, 7, 0, 6) << endl;
    cout << burteforce(arr, 7) << endl;
    system("pause");
    return 0;
}
