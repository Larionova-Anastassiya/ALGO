#include <bits/stdc++.h>

using namespace std;

void heapify(long long array[], long long n, long long i) {
    long long larg = i; //minimum 1

    long long right = 2 * i + 2; //формулы специальные
    long long left = 2 * i + 1;
    

    if (left < n && array[left] > array[larg]) //если левое больше
        larg = left;
 
    if (right < n && array[right] > array[larg]) //если правое больше
        larg = right;
 
    if (larg != i) { //не равно тогда меняем значение и присваиваем largest
        swap(array[i], array[larg]);
        heapify(array, n, larg);
    }
}


void heapify2(long long arr[], long long n, long long i) {
    long long minimum2 = i; //minimum 2

    long long left2 = 2 * i + 1;  //формулы специальные
    long long right2 = 2 * i + 2;

    if (left2 < n && arr[left2] < arr[minimum2]) //если левое больше
        minimum2 = left2;
 
    if (right2 < n && arr[right2] < arr[minimum2]) //если правое больше
        minimum2 = right2;
 
    if (minimum2 != i) { //не равно тогда меняем значение и присваиваем minimum2
        swap(arr[i], arr[minimum2]);
        heapify2(arr, n, minimum2);
    }
}



//сортируем данные вызывая heapify
void heapSort(long long arr[], long long n){
    for (long long i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (long long i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
 

//главная работа
long long main(){
    long long n;
    cin>>n;
    long long array[n]; //обьявляем массив нашего размера
    for(long long i = 0; i < n; i++){
        cin >> array[i]; //вводим в массив данные
    }
    heapSort(array,n);//сортируем по нашему числу
    
    //VALUES
    long long ans_sum = 0; //answer
    long long size = n;
    long long temp = 0;

    for(long long i = 0;i < n-1; i++){
        long long temp = 0;

        temp = array[0];
        array[0] = 0;
        size--;

        swap(array[0], array[size]);
        heapify2(array, size, 0);
        
        array[0] += temp;
        ans_sum += array[0];
        heapify2(array, size, 0);
    }

    cout << ans_sum;
}