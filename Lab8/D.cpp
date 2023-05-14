#include <bits/stdc++.h>
using namespace std;

typedef long long ll; //переименовали для упрощения 


//constants for working and answers
ll MAX_constant = 1e9 ;


//specific size for all values

ll pows1[200005];
ll hash_s[200005];



/*
Input
2
aba
bab
ababababac
6
beta
alpha
haha
delta
dede
tata
dedeltalphahahahototatalpha
0
Output
4
aba
2
alpha
haha
*/


int main() {

    pows1[0] = 1; //first index

    //first vector
    for (int i = 1; i < 100005; i++) {
        pows1[i] = (pows1[i - 1] * 31) % MAX_constant;
    }




    while(true) {

        int n;
        cin >> n; //size how strings

        int maximum_val = -1; //for ans integer


        if (n == 0) //return all answer and break work
            break;


        pair<string,int> str_ans[n];



        for (int i = 0; i < n; i ++) {
            cin >> str_ans[i].first;

            str_ans[i].second = 0;
        }


        string s;
        cin >> s; //input new string

        int n2 = s.size(); //this size string equals size all

        for (int i = 0; i < n2; ++i) {
            hash_s[i + 1] = (hash_s[i] + (s[i] - 'a' + 1) * pows1[i]) % MAX_constant;
        }



        for (int i = 0; i < n; i ++) {

            ll hash_t = 0;

            for (int j = 0; j < str_ans[i].first.size(); j ++) {

                hash_t = (hash_t + (str_ans[i].first[j] - 'a' + 1) * pows1[j]) % MAX_constant; //formulas specific

            }


            for (int ii = 0; ii + str_ans[i].first.size() - 1 < n2; ii ++) {
                ll cur = (hash_s[ii + str_ans[i].first.size()] + MAX_constant - hash_s[ii]) % MAX_constant;

                if (hash_t * pows1[ii] % MAX_constant == cur){

                    str_ans[i].second++;
                    maximum_val = max(maximum_val, str_ans[i].second);
                }
            }
        }


        //output all answers
        //the dominating patterns. If there are several dominating patterns, output them in order they appear in the input.
        cout << maximum_val << endl;


        for (int i = 0; i < n; i ++) {
            if (str_ans[i].second == maximum_val) {
                cout << str_ans[i].first << endl;
            }
        }
    }
}