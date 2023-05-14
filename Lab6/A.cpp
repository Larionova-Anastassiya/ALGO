#include<bits/stdc++.h>
using namespace std;

bool vowels_check(char vow1, char vow2){
    //check if this vowels in english

    //Vowel letters are a, e, i, o and u.
    bool isVowel1 = (vow1 == 'a' || vow1 == 'e' || vow1 == 'i' || vow1 == 'o' || vow1 == 'u');
    bool isVowel2 = (vow2 == 'a' || vow2 == 'e' || vow2 == 'i' || vow2 == 'o' || vow2 == 'u');


    //check if this not vowel 1 and 2
    if(isVowel1 && !isVowel2){
        return true;
    }


    if(!isVowel1 && isVowel2){
        return false;
    }


    return vow1 < vow2; //return result this function
}


//basic function for Heap
void heapify(char a[], int size, int i ){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    

    if(l < size && vowels_check(a[l], a[largest])){
        largest = l;
    }

    if(r < size && vowels_check(a[r], a[largest])){
        largest = r;
    }

    if(largest != i){
        swap(a[largest], a[i]);
        heapify(a, size, largest);
    }
}



//Basic functions Heap sorting
void heapSort(char a[], int size){


    for(int i = (size - 1) / 2; i >= 0; i--){
        heapify(a, size, i);
    }

    for(int i = size - 1; i >= 0; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}


/*
Input
5
abcde

Output
aebcd

First output vowels
*/
int main(){
    int n;
    cin >> n; //size

    char a[n];


    for(int i = 0; i < n; i++){
        cin >> a[i]; //input values
    }

    heapSort(a, n);


    for(int i = n - 1; i >= 0; i--){
        cout << a[i]; //output results
    }
    return 0;
}