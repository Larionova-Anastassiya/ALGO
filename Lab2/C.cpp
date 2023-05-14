#include <iostream>
using namespace std;

//обьявляем наши данные
struct Node{
    int val; //хранит значение цифры
    Node*next; //хранит значение след. ноды
    Node (int x){
        this->val=x; //значение приравнивает или this->val = val
        next=NULL;
    }
};

//обьявляем класс и голова NULL
class ll{
public: 
Node*head; //определяет голову
    ll(){
    head = NULL;
}

// функция добавления данных
void push(int val){
    Node*newNode=new Node(val); //создает голову первую
    if (head==NULL){ //если равно пустоте то голова равна нашей введенной
        head=newNode;
    }
    else {
        Node*i = head; 
    while (i->next!=NULL){ //если следующее значение не пустота то оно равно следующему элементу
        i=i->next;
    }
        i->next=newNode;
}
}

// функция вывода данных
void print(){
    Node*i=head;

    while(i!=NULL){ //пока не равно пустоте то будет смещать значение 

    cout << i ->val<<" ";
    i = i->next;
}
}
};

int main (){
    // вводим нашу цифру сколько чисел
    int n;
    cin >> n;
    ll list; //вызов листа
    for (int i=0; i<n; i++){
        int a;
        cin >> a; //вводим наши числа 
        if (i%2==0){ //если делится на 2
            list.push(a); //то добавит в лист
        }
    }
    list.print(); //вывод используя функцию нечетные числа
}