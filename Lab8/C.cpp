#include <bits/stdc++.h>
using namespace std;


typedef long long ll; //переименовали для упрощения 

//constants for working and answers
ll MAX_constant = 1e9;
ll MAX_constant2 = 1e9 + 7;


//specific size for all values
bool true_or_false[200005];

ll pows[200005];
ll pows2[200005];

ll hashes[200005];
ll hashes2[200005];



/*
Input
abaaba
2
ab
ba

Output
YES
*/



int main() {
    string s;
    cin >> s; //abaaba

    int n_size_s = s.size();

    pows[0] = 1; //first index
    pows2[0] = 1; //second index

    //first vector (massiv) pows
    for (int i = 1; i < n_size_s; i++) {
        pows[i] = (pows[i - 1] * 31) % MAX_constant;
    }

    //second vector (massiv) pows
    for (int i = 1; i < n_size_s; i++) {
        pows2[i] = (pows2[i - 1] * 37) % MAX_constant2;
    }


    //for hash formulas
    for (int i = 0; i < n_size_s; ++i) {
        hashes[i + 1] = (hashes[i] + (s[i] - 'a' + 1) * pows[i]) % MAX_constant;
    }

    for (int i = 0; i < n_size_s; i ++) {
        hashes2[i + 1] = (hashes2[i] + (s[i] - 'a' + 1) * pows2[i]) % MAX_constant2;
    }




    int n;
    cin >> n; // number of smaller tapes 



    //specific constants
    int left = s.size() + 1, right = 0;



    while(n--){

        string t_str;
        cin >> t_str; //strings


        //specific constants
        ll hash_t = 0;
        ll hash_t2 = 0;

        for (int i = 0; i < t_str.size(); i ++) {
            hash_t = (hash_t + (t_str[i] - 'a' + 1) * pows[i]) % MAX_constant;
        }

        for (int i = 0; i < t_str.size(); i ++) {
            hash_t2 = (hash_t2 + (t_str[i] - 'a' + 1) * pows2[i]) % MAX_constant2;
        }




        //works for answers
        for (int i = 0; i + t_str.size() - 1 < n_size_s; i++) {

            ll cur = (hashes[i + t_str.size()] + MAX_constant - hashes[i]) % MAX_constant;
            ll cur1 = (hashes2[i + t_str.size()] + MAX_constant2 - hashes2[i]) % MAX_constant2;



            if (hash_t * pows[i] % MAX_constant == cur && hash_t2 * pows2[i] % MAX_constant2 == cur1) {

                bool ok = true;

                //counters
                int k = 0;
                int j = i;



                while(k < t_str.size()){

                    if (t_str[k] != s[j]){
                        ok = false;
                        break;
                    }

                    k++;j++;
                }



                if(ok) {
                    left = i;
                    right = i + t_str.size() - 1;

                    for (int ii = left; ii <= right; ii++) {
                        true_or_false[ii] = true;
                    }
                }
            }
        }
    }


    //output answers
    for (int i = 0; i < s.size(); i ++) {

        if (!true_or_false[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}