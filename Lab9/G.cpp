#include<bits/stdc++.h>
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
zzz

Output
1

*/


int main() {
    // Values
    string str; 
    cin >> str;

    
    vector<int> prefix_index = pref_func_string(str);

    int ans = str.size() - prefix_index.back();
    cout << ans;
    return 0;
}