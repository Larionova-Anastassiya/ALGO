#include <iostream>
using namespace std;


//use merge sort use 3 indexes
void mergeSortfirst(int array[], int left, int middle, int right){
    int index, index2, cnt;
    index = left;
    index2 = middle + 1;
    cnt = left;
    int array2[right + 1];

    //conditions for merge sort first
    while(index <= middle && index2 <= right){

        if(array[index] < array[index2]){
            array2[cnt] = array[index];
            index++;
            cnt++;
        }

        else{
            array2[cnt] = array[index2];
            index2++;
            cnt++;
        }
    }


    // for but dont use "int i = .." because we have index = left;
    for(; index <= middle; index++){
        array2[cnt] = array[index];
        cnt++;
    }


    for(; index2 <= right; index2++){
        array2[cnt] = array[index2];
        cnt++;
    }


    for(index = left; index <= right; index++){
        array[index] = array2[index];
    }
    
}





//sort for answers
void mergeSort(int array[], int left, int right){

    if(left < right){

        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        //sort all
        mergeSortfirst(array, left, middle, right);
    }
}



int main(){
    int n,m;
    cin >> n >> m; //size array and second array

    int array[n];
    int array2[m];


    //insert values in first array and sorting
    for(int index = 0; index < n; index++) {
        cin >> array[index];
    }
    mergeSort(array, 0, n - 1);
    

    //insert values in second array and sorting
    for(int index = 0; index < m; index++) {
        cin >> array2[index];
    }
    mergeSort(array2, 0, m - 1);



    //output answers
    for(int index = 0; index < n; index++) {

        for(int index2 = 0; index2 < m; index2++) {

            if(array[index] == array2[index2]) {

                cout << array[index] << " ";
                array2[index2] = -1;
                index++;
                continue;

            }
        }
    }
}