#include <bits/stdc++.h>
using namespace std;

typedef long long ll; //переименовали для упрощения 


/*
Input
aab

Output
5
*/

int main(){

    string s; 
    cin >> s; //aab

    
    //constants for working and answers
    ll MAX_constant = 9007199254740881;

    //vectors for answer
    vector<vector<ll>> l;
    unordered_map<ll,int> m;


    //все виды перемещения букв
    for(int i = 0; i < s.length(); i++) {

        //constants
        ll sum = 0;
        ll prefix = 0;
    

        for(int j = i; j < s.length(); j++) {

            prefix = (prefix*256+s[j]) % MAX_constant; //formulas


            if(m.find(prefix) == m.end()) {

                l.push_back({i, j}); //pair
            }

            m[prefix] = 1; //next element
        }
    }

    cout << l.size() << endl; //answer all many different substrings

}