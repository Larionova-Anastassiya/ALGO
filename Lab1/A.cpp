#include <bits/stdc++.h>
using namespace std;

int main(){   

    int n; cin >> n; //введем сколько всего чисел


    for(int i=0; i<n; i++){

        deque <int> d;
        int num; cin >> num; //вводим наши числа до количества н

        for(int j=num; j!=0; j--){
            d.push_front(j); //добавляем значения
            for(int c=0; c<j; c++){
                d.push_front(d.back()); //переносим значение в конец
                d.pop_back();
            }
        }

        deque <int>:: iterator it; //используется для обращения к определенному элементу 
        for(it = d.begin(); it!=d.end(); it++){
            cout << *it << " "; //вывод ответа
        }
        cout << endl; //с новой строки
    }
}