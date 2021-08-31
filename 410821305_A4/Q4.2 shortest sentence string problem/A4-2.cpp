#include <bits/stdc++.h>
using namespace std;

int n;

void find_sentence(string *arr);
int findOverlapLength(string str1, string str2);

void run()
{
    cout << "Enter the total input keywords: ";
    cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = "";
    }
    for(int i = 0; i < n; i++){
        cout << "Keyword " << i + 1 << ": ";
        cin >> arr[i];
    }
    find_sentence(arr);
}

void find_sentence(string *arr)
{
    vector<string> List;
    for(int i = 0; i < n; i++){
        List.push_back(arr[i]);
    }
    while(List.size() != 1){
        int trace_index_i = 0, trace_index_j = 1, maxOverlapLength = 0;
        for(int i = 0; i < List.size(); i++){
            for(int j = 0; j < List.size(); j++){
                if(i == j){
                    continue;
                }
                int temp = findOverlapLength(List[i], List[j]);
                if(maxOverlapLength < temp){
                    maxOverlapLength = temp;
                    trace_index_i = i;
                    trace_index_j = j;
                }
            }
        }
        //i tail and j head combine
        List[trace_index_j].erase(0, maxOverlapLength);
        List[trace_index_i] += List[trace_index_j];
        List.erase(List.begin() + trace_index_j);
    }
    cout << "The shortest sentence is: " << List[0] << endl;
    cout << "The length of the sentence is: " << List[0].length() << endl << endl;
}

int findOverlapLength(string str1, string str2)
{
    //find the longest overlap length of the given two strings
    int best = 0, temp_length = 0;
    string temp1, temp2;
    for(int i = 1; i <= min(str1.length(), str2.length()); i++){
        temp1 = "", temp2 = "", temp_length = 0;
        for(int j = 0; j < i; j++){
            temp1 = str1[ str1.length() - 1 - j ] + temp1;
            temp2 += str2[j];
            temp_length++;
        }
        if(temp1 == temp2 && best < temp_length){
            best = temp_length;
        }
    }
    return best;
}

int main()
{
    while(true){
        run();
    }
    return 0;
}
