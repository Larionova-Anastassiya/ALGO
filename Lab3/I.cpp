# include <bits/stdc++.h>
using namespace std;


//функция проверки и поиска (по середине используя binarySearch)
int binarySearch(int arr[], int low, int high, int x){
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) // If the element is present at the middle
            return mid;
 
        if (arr[mid] > x)  //если середина больше то уйдет влево по значениям
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x); //иначе уйдет вправо (так как больше середины)
    }
    return -1; //если не прошел поиск то -1
}


//основная работа добавление данных
int main(){ 

    //создать свой массив
    int n, k ; //вводные данные (кол во чисел и сами числа в массиве после (что найти))
    cin >> n;
    int arr[n]; //массив с данными 

    for (int i=0; i<n; i++)
        cin >> arr[i]; //вводим данные в массив


    cin >> k; 


    int p = sizeof(arr) / sizeof(arr[0]);  //high = максимальный индекс (верх) = p - 1   low = 0 (minimum index) 
    int result = binarySearch(arr, 0, p - 1, k); //вызов функции с данными

    if (result == -1){
        printf("No");
    } else printf("Yes");

    return 0;
}