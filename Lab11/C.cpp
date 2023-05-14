#include <bits/stdc++.h>
using namespace std;

//static function for all tasks (for example kilom and par_fir)
vector<int> root; //fir element

int parent(int value) {

    while(value != root[value]) {

        root[value] = root[root[value]]; //root in root
        value = root[value];

    }

    return value;
}

void find_union(int fir, int sec) {

    int par_fir = parent(fir);
    int par_sec = parent(sec);

    root[par_fir] = root[par_sec];

}



/*
the total w_f_cost of the project

Examples

Input
7 6
4 3
both 2 7 4
both 1 7 2
big 4 6 1
big 3 7 3
small 5 6 1
both 5 7 10

Output
67

*/


int main(){
    //values
    int n, m;
    int x, y;
    int cnt_count = 0;
    int answer = 0;
    string str; //both, big, small
    int fir, sec, kilom; // a, b, c

    //input
    cin >> n >> m; //sizes
    cin >> x >> y;

    //specific values
    int min_x_y = min(x, y);
    vector<pair<int, pair<int, int>>> weight_edges;


    //input root
    for(int i = 0; i < n; i++) {
        root.push_back(i);
    }

    
    //input values in tasks (both 2 7 4)
    for(int i = 0; i < m; i++) {
        cin >> str;
        cin >> fir >> sec >> kilom;

        fir--;
        sec--;


        //conclusion with strings //create pairs
        if(str == "both") {
            weight_edges.push_back(make_pair(min_x_y * kilom, make_pair(fir, sec)));
        }


        else if(str == "big") {
            weight_edges.push_back(make_pair(x * kilom, make_pair(fir, sec)));
        
        }


        else if(str == "small") {
            weight_edges.push_back(make_pair(y * kilom, make_pair(fir, sec)));
        }
    }



    //all sorting
    sort(weight_edges.begin(), weight_edges.end());



    //Solutions
    //counts all

    for(int i = 0; i < weight_edges.size(); i++) {

        //conclusion where we have break
        if(cnt_count >= n-1) {
            break;
        }



        int w_f_cost = weight_edges[i].first;
        int w_s_fir = weight_edges[i].second.first;
        int w_s_sec = weight_edges[i].second.second;

        
        int val1 = parent(w_s_fir);
        int val2 = parent(w_s_sec);


        if(val1 != val2) {

            cnt_count++;
            answer += w_f_cost;


            find_union(w_s_fir, w_s_sec);
        }
    }


    //output results
    cout << answer;


}