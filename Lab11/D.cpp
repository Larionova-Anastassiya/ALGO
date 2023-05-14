#include <bits/stdc++.h>
using namespace std;

//static function for all tasks (for example c and par_fir)
vector<int> root; //first element

int parent(int value) {

    while(value != root[value]) {

        root[value] = root[root[value]]; //root in root
        value = root[value];

    }

    return value;
}

void find_union(int first, int second) {

    int par_fir = parent(first);
    int par_sec = parent(second);

    root[par_fir] = root[par_sec];
    
}



/*
the minimum possible w_f_cost to make the graph connected


Examples

Input
3
0 0 28
0 0 0
28 0 0

Output
0

*/

int main() {
    //values
    int n;
    int count = 0;
    int ans = 0;

    cin >> n; //input size for matrix

    int a[n][n];
    vector<pair<int, pair<int, int>>> weight_vec;



    //input root
    for(int i = 0; i < n; i++) {
        root.push_back(i);
    }

 
    //input values in matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];


            if(i < j) {
                weight_vec.push_back(make_pair(a[i][j], make_pair(i, j))); //create pairs
            }
        }
    }


    //all sorting
    sort(weight_vec.begin(), weight_vec.end());



    //Solutions
    //counts all
    for(int i = 0; i < weight_vec.size(); i++) {

        //conclusion where we have break
        if(count >= n - 1) {
            break;
        }

        int w_f_cost = weight_vec[i].first;
        int w_s_fir = weight_vec[i].second.first;
        int w_s_sec = weight_vec[i].second.second;

        int val1 = parent(w_s_fir);
        int val2 = parent(w_s_sec);

        if(val1 != val2) {

            count++;
            ans += w_f_cost;


            find_union(w_s_fir, w_s_sec);
        }
    }


    //output results
    cout << ans;


}