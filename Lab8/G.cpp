#include <bits/stdc++.h>
using namespace std;


typedef long long ll; //переименовали для упрощения 


ll MAX_constant = 1e9;

/*
Input
abracadabra
5
1 1
1 2
3 4
1 5
1 4

Output
5
2
2
1
2
*/

int main() {
    string S;
    cin >> S; //abracadabra


    int n_size = S.size();


    //creating vectors for work
    vector<long long> pows(S.size());
    vector<ll> vec2(n_size + 1, 0);


    pows[0] = 1; //first index


    //first vector
    for (int i = 1; i < (int)pows.size(); i++) {
        pows[i] = (pows[i - 1] * 31) % MAX_constant; //specific formulas
    }

    //second vector
    for (int i = 0; i < n_size; ++i) {
        vec2[i + 1] = (vec2[i] + (S[i] - 'a' + 1) * pows[i]) % MAX_constant;
    }



    int q;
    cin >> q; //size numbers (5) 


    //Then next  q lines contains queries, each query is two integer L and R

    while(q--){
        int L, R;
        cin >> L >> R; //1 1 ...

        L--;

        string str_for_ans = "";


        for (int i = L; i < R; i ++){
            str_for_ans += S[i]; //all values in first string 
        }


        ll heap = 0;
        int answer = 0;


        // for ht
        for (int i = 0; i < str_for_ans.size(); i ++){
            heap = (heap + (str_for_ans[i] - 'a' + 1) * pows[i]) % MAX_constant;
        }

        //for answer
        for (int i = 0; i + str_for_ans.size() - 1 < n_size; i++) {
            ll cur = (vec2[i + str_for_ans.size()] + MAX_constant - vec2[i]) % MAX_constant;

            if (heap * pows[i] % MAX_constant == cur) 
                answer++;

        }


        cout << answer << endl; //all answer for all L and R
    }

}