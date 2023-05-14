#include <iostream>
using namespace std;

long long arr_main[100000];
int size = 0;

//Binary Heap basic
int parent(int index_main){
    return (index_main - 1) / 2;
}

int leftChild(int index_main){
    return (2 * index_main) + 1;
}

int rightChild(int index_main){
    return (2 * index_main) + 2;
}


/*
Update heap. And return position
Input
6
12 6 8 3 4 7
2
5 11
3 6
Output
1
3
15 12 14 3 6 7 
*/

int main(){

    //6
    //12 6 8 3 4 7

    int n;
    cin >> n; //first size

    long long value;

    for (int i = 0; i < n; i++) {
        cin >> value; //insert all values


        //function insert
        arr_main[size] = value;
        size++;

        int index_main = i;
        int first_parent = parent(index_main);

        //function shiftUp in Heap
        while(index_main != 0 && arr_main[first_parent] < arr_main[index_main]) {
            
            swap(arr_main[first_parent], arr_main[index_main]);
            index_main = first_parent;
            first_parent = parent(index_main);

        }
    }


    //2
    //5 11
    //3 6
    int q;
    cin >> q; //second size
    long long index_main, value2;


    for(int i = 0; i < q; i++){

        cin >> index_main >> value2; 

        //change function
        arr_main[index_main-1] += value2;
        index_main -= 1;
        int first_parent = parent(index_main);

        //conditions and changes
        while(index_main != 0 && arr_main[first_parent] < arr_main[index_main]){
            swap(arr_main[first_parent], arr_main[index_main]);
            index_main = first_parent;
            first_parent = parent(index_main);
        }


        index_main++;
        cout << index_main << endl; //where we update
    }

    for(int i = 0; i < size; i++){
        cout << arr_main[i] << ' '; //answer updates heap
    }
}