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
hello 2
helloThomashelloArthurhelloJohnhello

Output
YES
*/


int main() {
    //Values
    string s, s2; //2 strings
    int cnt_need;
    int cnt_have = 0;

    cin >> s >> cnt_need; //need prefix in string
    cin >> s2; //string and prefix for string



    vector<int> prefix = pref_func_string(s + "#" + s2);

    // //Where prefix and cout this
    for (int i = 0; i < prefix.size(); i++) {
        if (prefix[i] == s.size()) {
            cnt_have++;
        }
    }


    //Answers
    if (cnt_have >= cnt_need)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}