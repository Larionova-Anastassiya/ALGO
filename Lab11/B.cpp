#include <bits/stdc++.h>
using namespace std;

/*
Output format
Print the only integer c - amount of money that Jonathan will spend to connect islands in his kingdom.

Examples
Input
5
2 5 4 2 8

Output
27

*/
int main() {
    //values
    int n;
    int ans = 0;


    cin >> n; //input size massiv

    //input values in massiv  (arrays)
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    //all sorting 
    sort(arr, arr+n); //2 2 4 5 8


    //couting for answers with sorting. In the first example you can construct four bridges between islands 1 and 2, 3 and 4, 4 and 5, 1 and 4.
    for(int i = 1; i < n; i++) {
        ans += arr[i] + arr[0];
    }

    //Output answers
    cout << ans;
    return 0;
}