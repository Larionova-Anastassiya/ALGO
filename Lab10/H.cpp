#include <iostream>
#include <vector>
#include <algorithm>

// or #include <bits/stdc++.h>

using namespace std;


/*
Посчитать острова - которые компонентно связаны

Input
4 5
11110
11010
11000
00000

Output
1


Input
4 5
11000
11000
00100
00011

Output
3
*/

//GLOBAL VALUES FOR SOLUTION

const int MAXIMUM = 105; //because size (1≤n≤100)
char arr[MAXIMUM][MAXIMUM]; //array for input and output

int n, m; //size for line and number vertices

bool used[MAXIMUM][MAXIMUM]; //for checked if you have this (all false)


//DFS 
void dfs(int i, int j){

    //CHECKING for STOP
    if (i < 1 || j < 1 || i > n || j > m) 
        return;
    
    if (used[i][j]) 
        return;
    
    if (arr[i][j] == '0')
        return;

    
    used[i][j] = true; //this point true


    //WORKING
    dfs(i, j + 1); //right
    dfs(i, j - 1); //left
    dfs(i - 1, j); //up
    dfs(i + 1, j); //down

}



//working
int main(){
    //values for answer use counter
    int answer = 0;

    //input
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }


    //solution 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (arr[i][j] == '1' && !used[i][j]) {

                dfs(i, j);
                answer++;

            }
        }
    }


    cout << answer << endl;

    return 0;
}