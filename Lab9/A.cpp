#include <bits/stdc++.h>
using namespace std;

//FUNCTIONS
vector<int> pref_func_string(string s) {
    int size = (int)s.length(); //size with length string

    vector<int> pref(size);

    for (int i = 1; i < size; ++i) { //indexes for prefix

        //specofoc formulas for prefix functions
        int j = pref[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pref[j - 1];


        if (s[i] == s[j])
            ++j;

        pref[i] = j;
    }
    return pref;
}



//boolean check find substring or no
bool findsub(string strin, string patter) {
    //vector<int> answer;

    string all_string = patter + '#' + strin;
    vector<int> pref_vec = pref_func_string(all_string);


    for (int i = patter.size() + 1; i < all_string.size(); i++) {

        if (pref_vec[i] == patter.size())
            return true;  

    }

    return false; //if not find
}



/*
Input
abcd
cdabcdab

Output
3
*/

/*
For the first test case, answer is  3, because by repeating A three times (‘abcdabcdabcd‘), 
B is a substring of it. For the second case, we do not extend the string A and B is a substring of A. Number of repetitions of A is 1.
*/



int main() {
    //Values
    string s, s2;
    long long cnt = 1; //minimum

    cin >> s >> s2;//2 strings

    string minyo = s; //strings all
    
    while (s.size() < s2.size()) { //while s < s2 we + string and cout this
        s += minyo;
        cnt++;
    }


    //check for answer
    if (findsub(s, s2)) {
        cout << cnt;
        return 0;
    }

    if (findsub(s + minyo, s2)) {
        cout << ++cnt;
        return 0;
    }

    cout << -1;
    return 0;
}