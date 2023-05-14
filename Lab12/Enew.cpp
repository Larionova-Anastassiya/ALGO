#include <bits/stdc++.h>
using namespace std;


/*
Given a directed graph. Determine if it contains a cycle of negative we, and if so, print it.
*/

//global VALUES
vector<int> waysroad[410];
vector<int> airlanes_vec[410];
int arr[405][405];
int n, m, v;
const int INF = 1000000000;
bool cycle = false;





//CREATE EDGE
struct edge {
    int sr, de, we;
};
//or 
/*
class Edge{
    public:
    //VALUES
    int sr;
    int de;
    int we;

    //use all values create
    Edge(int sr, int de, int we){
        this->sr = sr;
        this->de = de;
        this->we = we;
    }
};
*/
vector<edge> edg;



//SOLUTION
void solve() {
    //values and vectors for solution
    vector<int> d (n, INF);
    d[v] = 0;
    vector<int> p (n, -1);
    int x;

    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < n * n; ++j) {
            if (d[edg[j].sr] < INF) {
                if (d[edg[j].de] > d[edg[j].sr] + edg[j].we) {
                    d[edg[j].de] = max (-INF, d[edg[j].sr] + edg[j].we);
                    p[edg[j].de] = edg[j].sr;
                    x = edg[j].de;
                }
            }
        }
    }


    if (x == -1) {
        cycle = false;
    }


    else {
        int y = x;
        for (int i = 0; i < n; ++i) {
            y = p[y];
        }

        vector<int> path;
        for (int cur = y; ; cur = p[cur]) {
            path.push_back (cur);
            if (cur == y && path.size() > 1)  break;
        }
        reverse (path.begin(), path.end());

        cout << "YES" << endl; //we have cycle
        cout << path.size() << endl; //print answer path if yes
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] + 1 << ' ';


        cout << endl;
        cycle = true;
    }
}




/*
Input
3
100000 100000 -51
100 100000 100000
100000 -50 100000

Output
YES
4
3 2 1 3 

*/



int main(){
    cin >> n;

    vector<int> d(n, INF);

    //insert values
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            edge cur;
            cin >> cur.we;
            cur.sr = i; cur.de = j;
            edg.push_back(cur);
        }
    }


    //find cycle
    for (int i = 0; i < n; i ++){
        v = i;
        solve();
        if (cycle) break; //and print answer if find
    }


    if (!cycle) { //if not find
        cout << "NO" << endl;
    }
}