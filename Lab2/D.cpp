#include<bits/stdc++.h>
using namespace std;

//создаем ноды со значениями и путями следющих нод
struct Node{
    int val;
    int cnt;
    Node * next;
    Node(int x){ //вводить значение и сразу назначает и начинается счетчик
        val = x;
        cnt = 1;
        next = NULL;
    }
};

//структура всего действия дабл структуры
struct ll{
    Node * head;
    Node * tail;
    ll(){ //по дефолту пустые голова и хвост
        head = NULL;
        tail = NULL;
    }

    //функция добавления значения
    void add(int x){
        Node * newNode = new Node(x);
        int cnt = 0; //первоначальные данные
        if(head == NULL){ //объявляем голову и хвост если их нет
            head = newNode;
            tail = newNode;
        } else{
            Node * cur = head; //иначе пробегает по каждому значению
            while( cur != NULL){ //пока не станет пустым будет выполнять
                if(cur -> val == x){
                    cur->cnt++; //увеличивать количество будет если равно х
                    break;
                }

                if(cur->next == NULL){ //если пустое следующее то новая нода
                    cur->next = newNode;
                    break;
                }
                cur = cur->next; //следующий пробег по ноде
            }
        }
    }

    //функция нахождения моды
    int findMode(){
        Node * cur  = head; //начиная с головы
        int mode  = 0; //первоначальное значение
        while(cur != NULL){ //пока не пустое будет проходить по элементам
            if(cur -> cnt > mode){
                mode = cur -> cnt; //приравняет что это мода (чаще встречается) если перечислений больше
            }
            cur = cur -> next; 
        }
        return mode; //вернет результат
    }


    //функция обратно перевернет значения
    void reverse(){
        Node * first = head; //первое значение это голова а второе пустое
        Node * second = NULL;
        while(first->next != NULL){
            second = first-> next; //пока не пустое то поменяет местами
            while (second != NULL) { //пока второе не пустое продолжит менять дальше элементы
                if(first->val < second->val){ //если первое значение меньше второго
                    swap(first->val, second-> val); // swap - обменять значения двух переменных, которые содержат одинаковые типы данных
                    swap(first->cnt, second->cnt);
                }
                second = second -> next; // следующий элемент
            }
            first = first -> next;
            
        } 
    }

    //вывод результата
    void print(){
        Node * cur = head;
        int mode = findMode();   //вводим перемнную которая находит по функции моду
        while(cur != NULL){  //пока не будет пустым наш проверяющий 
            if(cur -> cnt == mode){  //следующий элемент счетчика равен моде (максимальному) то вывод значения ноды
                cout << cur->val << " ";
            }
            cur = cur->next;  //по следующему каждый элемент проверка
        }
    }

};



 //главная работа
int main(){
    int n; cin >> n;  //вводим сколько всего чисел будет
    ll l;  //вызываем структуру
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;  //вводим наши числа пока можем по размеру н
        l.add(x);  //добавлем наши значения 
    }
    l.reverse();  //развернем значения
    l.print();  //выведем ответ (значения которые встречаются чаще всего и по убыванию стоят)
    

    return 0;
}