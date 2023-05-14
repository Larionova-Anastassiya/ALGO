#include <bits/stdc++.h>
using namespace std;

// FUNCTIONS
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
zabcd
abcdz

Output
4
*/

int main() {
    // Values
    string s, s2;
    cin >> s >> s2; // 2 strings

    vector<int> prefix = pref_func_string(s + "#" + s2 + s2);

    // where this string equals
    for (int i = 0; i < prefix.size(); i++) {
        if (prefix[i] == s2.size()) {
            int ans = i - 2 * s2.size();
            cout << ans << endl;
            return 0;
        }
    }

    // if no answers
    cout << -1 << endl;
}