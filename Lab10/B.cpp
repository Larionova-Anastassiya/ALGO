#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

// or #include <bits/stdc++.h>

using namespace std;


/*
Вывести путь от 1 точки до 2 указанной

Examples
Input
5
0 1 0 0 1
1 0 1 0 0
0 1 0 0 0
0 0 0 0 0
1 0 0 0 0
3 5

Output
3
*/


//GLOBAL VALUES FOR SOLUTION

const int MAXIMUM = 105; //because size (1≤n≤100)

vector<int> g[MAXIMUM]; 
vector<int> d(MAXIMUM); //path distance
bool used[MAXIMUM]; //for checked if you have this (all false)



//working
int main(){
    //values
    int n;

    //input size
    cin >> n;
    //input matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {

            int x;
            cin >> x;

            if (x == 1) { //where 0 indicates the absence of an edge, 1 indicates the presence of an edge.
                g[i].push_back(j);
            }
        }
    }


    //input first and second values;
    int start, end;

    cin >> start >> end;


    //QUEUE for answer
    queue<int> que;


    que.push(start);
    used[start] = true; //this point true


    //solution 
    while (!que.empty()){

        int v = que.front();

        for (int i = 0; i < g[v].size(); i++) {
        
            int to = g[v][i]; //identificator dor go

            if (!used[to]) {

                used[to] = true; //если не отмечено

                que.push(to); //длобавим в очередь


                d[to] = d[v] + 1; //расстояние найдем
            }
        }


        que.pop(); //удалим из очереди
    }



    //OUTPUT Answer
    if (used[end]) {
        cout << d[end] << endl;
    }

    else {
        cout << -1 << endl; // If the path does not exist,
    }

    return 0;
}