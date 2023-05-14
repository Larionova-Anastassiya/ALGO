// Merging array2[] into array1[]

#include <bits/stdc++.h>
using namespace std;

 

int arr_spec[1000000];


void sortedMerge(int array1[], int array2[], int n, int m) {
  /*
  int index1 = n - 1;
  int index2 = m - 1;
 
  int lastIndex = n + m - 1;
 
  // Merge array1 and array2, starting from last element in each 
  while (index2 >= 0) {
 
    // End of array1 is greater than end of array2
    if (index1 >= 0 && array1[index1] > array2[index2]) {
      array1[lastIndex] = array1[index1]; // Copy Element
      index1--;
    } 
    
    else {
      array1[lastIndex] = array2[index2]; // Copy Element
      index2--;
    }

    lastIndex--; // Move indices
  }
  */
  int index1 = 0;
  int index2 = 0;
  int cnt = 0;


  while(index1 < n && index2 < m){

    if(array1[index1] < array2[index2]){
        arr_spec[cnt] = array1[index1];
        cnt++;
        index1++;
    }

    else{
        arr_spec[cnt] = array2[index2];
        cnt++;
        index2++;
    }
  }


  // for but dont use "int i = .." because we have index1 = 0;
  for(; index1 < n; index1++){
    arr_spec[cnt] = array1[index1];
    cnt++;
  }


  for(; index2 < m; index2++){
    arr_spec[cnt] = array2[index2];
    cnt++;
  }

}
 
//print answer
void printArray(int *arr_ans, int n, int m) {
  
  for(int i = 0; i < n + m; i++){
        cout << arr_ans[i] << " ";
    }
}
 


int main() {
    
  int n;
  cin >> n; //size first
    
  int arr1[n];
    
  for(int index1 = 0; index1 < n; index1++){
    cin >> arr1[index1];
  }
    
  int m;
  cin >> m; //size second
    
  int arr2[m];
    
  for(int index2 = 0; index2 < m; index2++){
    cin >> arr2[index2];
  }
  
  
  sortedMerge(arr1, arr2, n, m);

  printArray(arr_spec, n, m);
  
  return 0;
}
