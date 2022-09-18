#include <bits/stdc++.h>
using namespace std;


int main(){
    deque<int> deq; //наш основной с чем работать


    while (true) { //пока работает выполняем команды

        char a;
        int b;
        cin >> a; //вводить знаки

        if (a=='!'){ //показать результат и закончить цикл
            break;
        }

        else if( a=='*'){ //надо сложить первый и последний и удалить их

           if(deq.size() == 0 ){ //но если их нет то ошибка
            cout<< "error\n";
           }

           else {//выполняем это действие
            int s = 0;
            s = deq.front() + deq.back(); //складываем начало и конец
            cout<< s << endl; //вывод ответа
            if (deq.size() == 1){
                deq.pop_back();
            }
            else{
            deq.pop_back(); //убираем эти два числа после сложения
            deq.pop_front();
            }
           }

        }

        else if( a=='+'){ //надо добавить элемент
           cin>> b; //ввод его
           deq.push_back(b);
        }


        else if( a=='-'){ //надо убрать элемент
           cin>> b;
           deq.push_front(b);
        }

    }
}