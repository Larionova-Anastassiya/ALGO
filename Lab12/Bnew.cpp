#include <bits/stdc++.h>
using namespace std; 

/*
Output format
Print one single number - the shortest distance to grandmother’s village 
so that Red Riding Hood can buy all the necessary presents along the way. 
If there is no such path then print -1.*/


//global VALUES
int INF = 1000000000; 
vector<pair<int,int>> g[200005]; 
vector<int> d(200005, INF); 
int n, m; 


/*
Input
4 5
1 2 3
3 4 7
1 3 1
3 2 1
2 4 6
1 2 3 4

Output
8
*/


//SOLUTION
int deikstra(int s, int end){ 
    d.clear(); 
    for(int i=0;i<200005;i++){ 
        d[i] = INF; 
    } 
    d[s] = 0; 
    set< pair<int,int> > q; 
    q.insert(make_pair(d[s],s)); 
    while(!q.empty()){ 
        int v = q.begin()->second; 
        q.erase(q.begin()); 
        for(int j = 0;j<g[v].size();j++){ 
            int to = g[v][j].first; 
            int len = g[v][j].second; 
            if(d[v] + len < d[to]){ 
                q.erase(make_pair(d[to], to)); 
                d[to] = d[v] + len; 
                q.insert(make_pair(d[to], to)); 
            } 
        } 
    } 
    return d[end]; 
} 

/*
Input
4 5
1 2 3
3 4 7
1 3 1
3 2 1
2 4 6
1 2 3 4

Output
8
*/

int main(){ 
    cin >> n >> m; 
    for (int i = 0; i < m; i++){ 
        int a,b,c; 
        cin >> a >> b >> c; 
        g[a].push_back({b,c}); 
        g[b].push_back({a,c}); 
    } 
    int q,w,e,r; 
    cin >> q >> w >> e >> r; 
    int a,b; 
    a = deikstra(q,w) + deikstra(w,e) + deikstra(e,r); 
    b = deikstra(q,e) + deikstra(e,w) + deikstra(w,r) ; 
    if(min(a,b) <= INF){ 
        cout << min(a,b); 
    }else{ 
        cout << -1; 
    } 
    return 0; 
}