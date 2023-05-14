#include<bits/stdc++.h>
using namespace std;

/*
Input
2
2
3
Output
YES
NO
*/

int main() {
    int n;
    cin >> n; //size operations

    long long value; //value for task


    for (int i = 0; i < n; i++) {
        cin >> value; //input values

        stack<int> stack;

        //пока вводим он будет проверять
        while (value) {
            if (!stack.empty()) { //new element first
                if (value % 2 == 1 && stack.top() == 0) { //усли не делится на 2 без остатка
                    stack.pop(); //delete
                } 
                
                else {
                    stack.push(value % 2);
                }
            } 
            
            else { 
                stack.push(value % 2);
            }


            value /= 2;
        }

        if (!stack.empty()) {
            cout << "NO\n";
        } 

        else {
            cout << "YES\n";
        }
    }
}