#include <bits/stdc++.h>
using namespace std; 


/*
Output format
Print one single number - the shortest distance to grandmother’s village 
so that Red Riding Hood can buy all the necessary presents along the way. 
If there is no such path then print -1.*/



//global VALUES
vector<int>waysroad[410]; 
vector<int>airlanes_vec[410]; 
int arr[405][405]; 


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
    int n,m; 
    cin >> n >> m; 


    //insert all values
    for(int i = 0; i < m; i++){ 
        int a,b; 
        cin >> a >> b; 
        a--; 
        b--; 
        waysroad[a].push_back(b); 
        waysroad[b].push_back(a); 
        arr[a][b] = 1; 
        arr[b][a] = 1; 
    } 


    for (int i = 0; i < n; i ++){ 
        for (int j = 0; j < n; j ++){ 
            if (arr[i][j] == 0 && i != j){ 
                airlanes_vec[i].push_back(j); 
            } 
        } 
    } 


    //SOLUTION

    //FIRST
    queue<int> q1; 
    vector<int> d1(n+1); 
    vector<bool> used1(n+1); 
    q1.push(0); 
    used1[0] = true; 
    while(!q1.empty()){ 
        int v = q1.front(); 
        q1.pop(); 
        for(int i = 0; i < waysroad[v].size(); i++){ 
            int to = waysroad[v][i]; 
            if(!used1[to]) { 
                used1[to] = true; 
                q1.push(to); 
                d1[to] = d1[v]+1; 
            } 
        } 
    } 

    //SECOND
    queue<int> q2; 
    vector<int> d2(n+1); 
    vector<bool> used2(n+1); 
    q2.push(0); 
    used2[0] = true; 
    while(!q2.empty()){ 
        int v = q2.front(); 
        q2.pop(); 
        for(int i = 0 ; i < airlanes_vec[v].size(); i++){ 
            int to = airlanes_vec[v][i]; 
            if(!used2[to]){ 
                used2[to] = true; 
                q2.push(to); 
                d2[to] = d2[v]+1; 
            } 
        } 
    } 


    //ANSWER with FIRST PART AND SECOND
    if (!used1[n-1] || !used2[n-1]){ 
        cout << -1; 
    } 
    else { 
        cout << max(d1[n-1], d2[n-1]); 
    } 
}