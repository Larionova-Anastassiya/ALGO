#include <bits/stdc++.h>
using namespace std;


long long power_index[55];

void change(){ //for precalc use indexes words

    power_index[0] = 1;

    for (int i = 1; i <= 55; i ++){
        power_index[i] = power_index[i - 1] * 2;
    }

}


/*
Input
5
7 15 59 147 371

Output
hello
*/
int main() {
    change();
    int n;
    cin >> n; //size word

    vector<long long> hash_answer(n);


    for (int i = 0; i < n; i++){
        cin >> hash_answer[i]; // 7 15 59 147 371
    }


    for (int i = 0; i < n; i ++){

        //use formulas in tasks output word

        if (i) 
            cout << char((hash_answer[i] - hash_answer[i - 1]) / power_index[i] + 97); 
        else 
            cout << char(hash_answer[i] / power_index[i] + 97);
    }
}
