#include <iostream>

using namespace std;

void heapify(int array[], int n, int i) {
    int larg = i; //minimum

    int right = 2 * i + 2; //формулы специальные
    int left = 2 * i + 1;
    

    if (left < n && array[left] > array[larg]) //если левое больше
        larg = left;
 
    if (right < n && array[right] > array[larg]) //если правое больше
        larg = right;
 
    if (larg != i) { //не равно тогда меняем значение и присваиваем largest
        swap(array[i], array[larg]);
        heapify(array, n, larg);
    }
}


//сортируем данные вызывая heapify
void heapSort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(array[0], array[i]);
         heapify(array, i, 0);
    }
}
 
  

//главная работа
int main() {
    int n;
    cin >> n;
    int array[n]; //обьявляем массив нашего размера
    for(int i = 0; i < n; i++){
        cin >> array[i]; //вводим в массив данные
    }

    heapSort(array, n);  //сортируем по нашему числу

    for(int i = n-1; i >= 1; i--){
        array[i-1] = abs (array[i-1] - array[i]); //постепенно проверка и сортируем
        heapSort(array, i); 
    }
    cout << array[0]; //минимальный вес нашего камня последнего
}

/*
Мы объединяем 7 и 8, чтобы получить 1, чтобы массив преобразовался в [2,4,1,1,1] затем мы объединяем 2 и 4, чтобы получить 2, 
чтобы массив преобразовался в [2,1,1,1] затем мы объединяем 2 и 1, чтобы получить 1, чтобы массив преобразовался в [1,1,1] 
затем мы объединяем 1 и 1 вполучите 0, чтобы массив преобразовался в [1], 
тогда это значение последнего камня.*/