#include <bits/stdc++.h>
using namespace std;


//FUNCTIONS
vector<int> pref_func_string(string str) {
    int size = (int)str.length(); //size with length string

    vector<int> pref(size);

    for (int i = 1; i < size; ++i) { //indexes for prefix

        //specofoc formulas for prefix functions
        int j = pref[i - 1];

        while (j > 0 && str[i] != str[j])
            j = pref[j - 1];


        if (str[i] == str[j])
            ++j;

        pref[i] = j;
    }
    return pref;
}


/*
Input
abacaba
aba

Output
2
1 5 
*/
int main() {
    //Values
    string s, s2; //2 strings
    int cnt = 0;

    cin >> s >> s2; //string and prefix for string



    vector<int> prefix = pref_func_string(s2 + "#" + s);

    for (int i = 0; i < prefix.size(); i++) {
        if (s2.size() == prefix[i]) {
            cnt++; //2
        }
    }


    cout << cnt << endl;


    //Where prefix
    for (int i = 0; i < prefix.size(); i++) {
        if (s2.size() == prefix[i]) {
            int ans = i - 2 * s2.size() + 1;
            cout << ans << " ";
        }
    }
}