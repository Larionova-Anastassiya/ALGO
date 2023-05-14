#include <iostream>
using namespace std;

int arr_main[100000];
int size = 0;

//Binary Heap basic
int parent(int index_main){
    return (index_main - 1) / 2;
}

int left(int index_main){
    return (2 * index_main) + 1;
}

int right(int index_main){
    return (2 * index_main) + 2;
}


/*
Input
3
1 2 3
Output
1

Output the number of vertices of a heap that have its right child’s value larger than the right’s one.
*/
int main(){
    int n;
    cin >> n; //size

    int value; // values

    for(int i = 0; i < n; i++) {
        cin >> value;

        //function insert
        arr_main[size] = value;
        size++;

        int index_main = i;
        int first_parent = parent(index_main);

        //function shiftUp in Heap

        while(i != 0 && arr_main[first_parent] < arr_main[index_main]) {

            swap(arr_main[first_parent], arr_main[index_main]);
            index_main = first_parent;
            first_parent = parent(index_main); 

        }
    }


    int answer = 0; //counting the number of vertices of a heap


    for(int i = 0; i < n; i++){

        if(left(i) < size && right(i) < size){  //condition have its right child’s value larger than the right’s one.

            if(arr_main[left(i)] < arr_main[right(i)]){
                answer++;
            }

        }
    }
    
    cout << answer;
}