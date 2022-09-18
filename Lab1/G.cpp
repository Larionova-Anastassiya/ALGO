/*Вам нужно найти простое число, индекс которого равен n-му простому числу. В качестве примера приведем простые числа
это: 2, 3, 5, 7... есть индексы 1,2,3,4 ... так что индексы 2 и 3 тоже являются простыми числами, поэтому у нас есть последовательность
"супер простых чисел", например: 3, 5, 11, 17... Найдите супер простое число.
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    bool m[10000];
    memset(m, true, sizeof(m));
    //MEMSET : Указатель на блок памяти для заполнения,
    //передается в виде целого числа, но функция заполняет блок памяти символом, преобразуя это число в символ,
    //Количество байт, которые необходимо заполнить указанным символом.


    int n;
    cin >> n; //введем число места суперпрайм
    for (int i = 2; i * i < 10000; i++){ //будет длиться до тех пор пока числа меньше проверка на прайм и сами прайм
        if (m[i] == true) {
            for (int j = i * i; j < 10000; j += i){ //умножение друг на друга проверка проходит
                m[j] = false;
            }
        }
    }

    vector < int > v; //наш ответ откуда брать результат
    for (int i = 2; i < 10000; i++){
        if (m[i]) v.push_back(i); //если подходит прайм то добавим
    }
    cout << v[v[n-1] - 1]; //выведем суперчисло на этом индексе

}