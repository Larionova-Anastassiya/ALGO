#include <bits/stdc++.h>
using namespace std; 

//specific another swap in algorithm
void swappingValues(int *first, int *second) {
  int val = *first;
  *first = *second;
  *second = val;
}


//for sort use specific partition
int partition(vector<int> v, int min, int max) {
  int pivot = v[max];
  int index = (min - 1);


  for (int index2 = min; index2 < max; index2++) {

    if (v[index2] <= pivot) {
      index++;
      swappingValues(&v[index], &v[index2]);
    }

  }

  //next values swap
  swappingValues(&v[index + 1], &v[max]);
  return (index + 1);
}



//basic sorting for vector use quick
void quickSort(vector<int> v, int min, int max) {

  //recursion sorting
  if (min < max) {
    int pi = partition(v, min, max);
    quickSort(v, min, pi - 1);
    quickSort(v, pi + 1, max);
  }

}



void printAnswer(vector<int> v) {
  for (int index = 0; index < v.size(); index++)
    cout << v[index] << " ";
}


/*
Input
4 2
1 2 2 1
2 2
Output
2 2 
*/


int main(){

  int n, m;
  cin >> n >> m; //size 2 vectors

  vector<int> vec, first, second; // vector answers and 2 vectors for input

  for(int index = 0; index < n; index++){
    int x;
    cin >> x; //input values first

    first.push_back(x);
  }


  for(int index2 = 0; index2 < m; index2++){
    int x;
    cin >> x; //input values second

    second.push_back(x);
  }

  //all sorting
  quickSort(first, 0, n-1);
  quickSort(second, 0, m-1);



  for(int index = 0; index < first.size(); index++){

    for(int index2 = 0; index2 < second.size(); index2++){

        if (first[index] == second[index2]){

          vec.push_back(first[index]);

          first.erase(first.begin() + index);
          second.erase(second.begin() + index2);

          index--;
          index2--;

        }
      }
  }

  //sorting answer
  sort(vec.begin(), vec.end());

  //output answer
  printAnswer(vec);
    
  /*OR 
  for (int index = 0; index < vec.size(); index++)
    cout << vec[index] << " ";
  */

  return 0;
}