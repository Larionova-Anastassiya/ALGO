#include <bits/stdc++.h>
using namespace std;


//GLOBAL values 
int row, column;
int arr[1005][1005];

//where we have answer and checked
queue <pair <int, int> > que_che;


/*
“0” - an empty cell;

“1” - a cell with the brown mushroom;

“2” - a cell with Mario.
*/

//Void functions for SOLUTION

void adjacentChek(int x, int y) {


    //CONDITIONS if need add (push) and what push
    if (x - 1 >= 0 && arr[x - 1][y] == 1) {
        arr[x - 1][y] = 2;

        //ADD
        que_che.push(make_pair(x - 1, y));
    }

    if (x + 1 < row && arr[x + 1][y] == 1) {
        arr[x + 1][y] = 2;

        //ADD
        que_che.push(make_pair(x + 1, y));
    }

    if (y - 1 >= 0 && arr[x][y - 1] == 1) {
        arr[x][y - 1] = 2;

        //ADD
        que_che.push(make_pair(x, y - 1));
    }

    if (y + 1 < column && arr[x][y + 1] == 1) {
        arr[x][y + 1] = 2;

        //ADD
        que_che.push(make_pair(x, y + 1));
    }
}





void counting() {
    //values what count walk and answer
    int ans = 0;


    while(!que_che.empty()) {

        int n = que_che.size();

        for(int i = 0; i < n; i++) {

            //(pairs) we have first and second values
            int firs = que_che.front().first;
            int secon = que_che.front().second;

            que_che.pop();
            adjacentChek(firs, secon); //cheking
        }


        if(!que_che.empty()) {
            ans++;
        }
    }



    //if 1 output -1
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {

            if(arr[i][j] == 1){
                cout << -1;
                return;
            } 
        }
    }  


    //OUTPUT
    cout << ans;
}



/*
Print the minimum time (in minutes) that must elapse until no cell will contain a brown mushroom. 
If any mushroom is unreachable for every Mario in a field print -1.

Examples
Input
3 3
2 1 1
1 1 0
0 1 1

Output
4
*/



int main(){

    cin >> row >> column; //number of rows of a field, number of columns

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {

            //add matrix
            cin >> arr[i][j];

            if(arr[i][j] == 2) {
                que_che.push(make_pair(i, j));
            }
        }
    }

    //OUTPUT ANSWER
    counting();
    return 0;
}