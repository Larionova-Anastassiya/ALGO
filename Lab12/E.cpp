#include <bits/stdc++.h>
using namespace std;


/*
Given a directed graph. Determine if it contains a cycle of negative we, and if so, print it.
*/

//global VALUES
int size_n;


//CREATE EDGE
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




//create GRAPH
class Graph{
    public:
    //VALUES (vector for all edges graph)
    vector <Edge *> edges_vec;


    //ADD EDGES Use 2 function

    //1 with edge
    void addEdge(Edge * e){
        edges_vec.push_back(e);
    }

    //2 with all values edges - new
    void addEdge(int sr, int de, int we){
        edges_vec.push_back(new Edge(sr, de, we));
    }
};




//Function for CYCLE
void cycleFinding(Graph * edges_vec){
    //VALUES (arrays for answers)
    bool visit[size_n];
    int answer[size_n];


    //chech all values
    for(int i = 0; i < size_n; i++){
        visit[i] = false;
        answer[i] = INT_MAX;
    }


    //default VALUES 
    answer[0] = 0;
    visit[0] = true;
    bool check = true;



    //SOLUTION FIND CYCLE
    for(int i = 1; i <= size_n - 1; i++){


        //when stoping work
        if(check = false){
            break;
        }

        //default
        check = false;



        //cheking all edges and find cycle
        for(int j = 0; j < edges_vec->edges_vec.size(); j++){

            int sr_in = edges_vec->edges_vec[j]->sr;
            int de_in = edges_vec->edges_vec[j]->de;
            int we_in = edges_vec->edges_vec[j]->we;


            if(answer[sr_in] != INT_MAX && we_in < answer[de_in]){
                check = true;
                visit[de_in] = true;
                answer[de_in] = we_in;
            }
        }
    }


    //OUTPUT answer if YES
    for(int i = 0; i < size_n; i++){
        cout << answer[size_n] << ' ';
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

    cin >> size_n;
    int x, y;

    pair <int, int> coords[size_n];
    for(int i = 0; i < size_n; i++){
        cin >> x >> y;
        coords[i] = make_pair(x, y);
    }

    Graph * edges_vec = new Graph();
    for(int i = 0; i < size_n; i++){
        for(int j = 0; j < size_n; j++){
            if(i == j){
                continue;
            }
            edges_vec->addEdge(i, j, abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second));
            edges_vec->addEdge(j, i, abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second));
        }
    }

    cycleFinding(edges_vec);
    return 0;
}