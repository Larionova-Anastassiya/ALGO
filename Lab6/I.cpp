#include <string>
#include <iostream>
using namespace std;

//basic function
void quickSort(string &str, int left, int right) {
    int low = left, high = right;
    int pivot = str[(low + high) / 2];


    do {
        while (str[low] < pivot) low++;

        while (str[high] > pivot) high--;

        if (low <= high) {
            swap(str[low], str[high]);
            low++; 
            high--;
        }
    }
    
    while (low <= high);
    /* recursion */

    if (left < high) quickSort(str, left, high);

    if (low < right) quickSort(str, low, right);
}

int main(){

  string str;
  //asdzxchfg
  cin >> str;

  quickSort(str, 0, str.size() - 1);
  cout << str;
  //acdfghsxz
}