#include <bits/stdc++.h>
using namespace std;


/*
Print “YES” if we can add 3 elements, otherwise print “NO”.


Input
4 4
1 1 0 1
1 1 1 1
0 1 1 0
1 1 0 1
1 2 4
2 3 4
1 2 2
3 3 4

Output
YES
NO
YES
NO
*/

int main() {


    //INPUT 

    //values
    int elem_n, quer_n; //the number of elements and number of queries.
    cin >> elem_n >> quer_n;

    //arrays for matrices
    int arr[elem_n][elem_n];

    //add all elements in matrix
    for(int i = 0; i < elem_n; i++){
        for(int j = 0; j < elem_n; j++){
            cin >> arr[i][j];
        }
    }


    //input The next n lines contains n integers a[i][j], that means element i can be added to element j if a[i][j] = 1 and if a[i][j] = 0 
    //they cannot be added. It is guaranteed that a[i][i] = 1

    //add all elements queries AND solution
    for(int i = 0; i < quer_n; i++){
        //values
        int a, b, c;
        cin >> a >> b >> c; // example 1 2 4
        /*
        1 2 4
        2 3 4
        1 2 2
        3 3 4
        */
        a--;
        b--;
        c--;



        //OUTPUT

        //ANSWERS use if, becoese we have 3 ways checked it
        if(arr[a][b] == 0){
            cout << "NO" << endl;
            continue;
        }


        if(arr[a][c] == 0){
            cout << "NO" << endl;
            continue;
        }


        if(arr[b][c] == 0){
            cout << "NO" << endl;
            continue;
        }


        //else we have answer YEP
        cout << "YES" << endl;
    }

    return 0;
}