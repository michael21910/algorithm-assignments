//author 410821305 Á§¯ª®¦
#include <iostream>
#include <cstring>

using namespace std;

bool palindrome(string s)
{
    for(int i = 0; i < s.length() / 2; i++){
        if(s[i] != s[s.length() - i - 1]){
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    while(true){
        cout << "---enter number 0 to exit this system---" << endl;
        cout << "Please enter a string: ";
        cin >> s;
        if(s == "0") break;
        if(palindrome(s)){
            cout << "This is a palindrome!" << endl;
        }
        else{
            cout << "This is not a palindrome!" << endl;
        }
    }
    return 0;
}
