#include <bits/stdc++.h>
using namespace std;

//basic function for Heap
void heapify(int a[], int size, int i){
    int biggest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if(l < size && a[l] > a[biggest]) 
        biggest = l;
    if(r < size && a[r] > a[biggest]) 
        biggest = r;

    if(biggest != i){
        swap(a[biggest], a[i]);
        heapify(a, size, biggest);
    }
}


//Basic functions Heap sorting
void heapSort(int a[], int size){

    for (int i = (size - 1) / 2; i >= 0; i--) {
        heapify(a, size, i);
    }


    for (int i = size - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}



//Output the pairs of points with the least absolute difference.
int main(){
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i]; //insert in arrays
    }

    heapSort(a, n);


    //after sorting with heap:
    int minimum = abs(a[1] - a[0]);
    
    for (int i = 1; i < n; i++) {

        if(minimum > abs(a[i] - a[i - 1])){
            minimum = abs(a[i] - a[i - 1]);
        }

    }


    //ANSWER:
    for (int i = 1; i < n; i++) {

        if(abs(a[i] - a[i - 1]) == minimum){
            cout << a[i - 1] << ' ' <<a[i] << ' ';
        }

    }
    
    return 0;
}