#include <bits/stdc++.h>
using namespace std;

/*
Input
3
c f g
a
Output
c
*/

int main(){
    int size;
    cin >> size;

    char value;

    vector<char> answer(size);

    for(int i = 0; i < size; i++) {
        cin >> answer[i];
    }

    cin >> value;

    bool run = true;

    for(int i = 0; i < size; i++) {

        if(char(answer[i]) > char(value)){

            cout << answer[i];
            run = false;
            break;

        }
       
    }

    //Output answer
    if(run) 
        cout << answer[0];

    return 0;
}