///Author: 410821305 Michael Hsueh
///The answer of 5-7 is at the "color" function.
///Execute the program to see more information.
#include <bits/stdc++.h>

using namespace std;

///Feel free to change the n here.
///n represents the length of the board.
const int n = 4;
string colored[n][n * 5];
/**
*   Why "colored[n][n * 5]" ? Why (n * 5)?
*   Since in the middle of a square, when coloring the invalid cell,
*   row_length = n, col_length = n, diagonal_length = sqrt(n) * 2 = 1.414 * 2 * n = 2.828 * n -> 3 * n.
*   n + n + 3 * n = n * 5.
*/

void init()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 5; j++){
            colored[i][j] = "";
        }
    }
    return;
}

bool putable(char arr[n][n], int row, int col)
{
    ///check the row that this queen at
    for(int i = 0; i < col; i++){
        if(arr[row][i] == 'Q'){
            return false;
        }
    }
    ///check let upper
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(arr[i][j] == 'Q'){
            return false;
        }
    }
    ///check left lower
    for(int i = row, j = col; i < n && j >= 0; i++, j--){
        if(arr[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

bool solved(char arr[n][n], int col)
{
    ///if the current solution is the correct solution
    ///the program will keep adding "col" until it is equal to n
    if(col >= n){
        return true;
    }
    for(int i = 0; i < n; i++){
        if(putable(arr, i, col)){
            arr[i][col] = 'Q';
            if(solved(arr, col + 1)){
                return true;
            }
        }
        arr[i][col] = '.';
    }
    return false;
}

void color(char arr[n][n], int row, int col, int counter)
{
    ///Color the row, column and diagonal according to the current queen.
    ///Order: row, column, left upper diagonal, right lower diagonal, right upper diagonal, left lower diagonal.
    ///For the order of the diagonal line, just like drawing a "x"
    ///I think this is more intuitive
    for(int i = 0; i < n; i++){
        if(arr[row][i] == '.'){
            arr[row][i] = 'x';
            colored[row][counter++] = to_string(row) + to_string(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i][col] == '.'){
            arr[i][col] = 'x';
            colored[row][counter++] = to_string(i) + to_string(col);
        }
    }
    for(int i = 1; row - i >= 0 && col - i >= 0 && arr[row - i][col - i] == '.'; i++){
        arr[row - i][col - i] = 'x';
        colored[row][counter++] = to_string(row - i) + to_string(col - i);
    }
    for(int i = 1; row + i < n && col + i < n && arr[row + i][col + i] == '.'; i++){
        arr[row + i][col + i] = 'x';
        colored[row][counter++] = to_string(row + i) + to_string(col + i);
    }
    for(int i = 1; row - i >= 0 && col + i < n && arr[row - i][col + i] == '.'; i++){
        arr[row - i][col + i] = 'x';
        colored[row][counter++] = to_string(row - i) + to_string(col + i);
    }
    for(int i = 1; row + i < n && col - i >= 0 && arr[row + i][col - i] == '.'; i++){
        arr[row + i][col - i] = 'x';
        colored[row][counter++] = to_string(row + i) + to_string(col - i);
    }
}

int main()
{
    init();
    char arr[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = '.';
        }
    }

    if(solved(arr, 0)){
        for(int i = 0; i < n; i++){
            int counter = 0;
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 'Q'){
                    color(arr, i, j, counter);
                }
            }
            ///Print out each table after meeting each queen.
            ///In the last graph, the cell that don't have queen
            ///will all be "x", so I decide to print it out every time
            ///just to make sure and to be clear.

            ///The numbers are the index
            ///The colored function display: ( row index (left index), column index (upper index) )
            cout << "  ";
            for(int k = 0; k < n; k++){
                cout << k << " ";
            }
            cout << endl;
            for(int a = 0; a < n; a++){
                for(int b = 0; b < n; b++){
                    if(b == 0){
                        cout << a << " ";
                    }
                    cout << arr[a][b] << " ";
                    if(b == n - 1){
                        cout << "|";
                    }
                }
                cout << endl;
            }
            for(int k = 0; k < n * 2 + 1; k++){
                cout << "-";
            }
            cout << endl;
        }

        for(int i = 0; i < n; i++){
            cout << "Cell colored when we meet Queen " << i + 1 << ": ";
            for(int j = 0; j < 5 * n && colored[i][j] != ""; j++){
                cout << "(" << colored[i][j][0] << ", " << colored[i][j][1] << ")" << " ";
            }
            cout << endl;
        }
    }

    else{
        cout << "Solution does not exist." << endl;
    }

    return 0;
}
