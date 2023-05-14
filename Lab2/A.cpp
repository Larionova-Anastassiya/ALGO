# include <bits/stdc++.h>
using namespace std;
 
//создаем ноды со значениями и путями следющих нод
struct Node {
  int val;
  Node * next;
 
  Node() { //по дефолту 0 и пустой
    val = 0;
    next = NULL;
  }
 
};
 
 
//функция поиска для места значения которое ближе по значению к к 
void search(Node * head ,int k){   
    int x = 2147483647 , cnt = 0, ans, y; //первоначальные данные
    Node * current = head;  //объявляем голову

    while (current != NULL) { //пока не равно пустоте будет выполняться

        //различные условия для поиска и определения у
        if(k >= 0 && current->val >= 0){ 
            y = abs(current->val - k); //возвращает модуль значения отнимая к
        }
        else if((current->val >= 0 && k < 0) || (current->val < 0 && k >= 0)){
            y = abs(abs(k)+abs(current->val));
        }
        else if(k < 0 && current->val < 0){
            y = abs(abs(current->val) - abs(k));
        }

        //если результат вышел меньше х то х равняется у
        if (y < x){
            x = y;
            ans = cnt;
        }

        current = current->next; //означает что это следующий элемент
        cnt++; //увеличиваем при каждом пробеге
    }

    cout << ans; //выведет ответ
    return;
}
 

//главная наша работа
int main() {
  int n, k;
  cin >> n; //вводим сколько всего числе будет
 
  Node * head = NULL, * tail = NULL; //все пустые пока что
  for (int i = 1; i <= n; ++i) { 
    int x;
    cin >> x; //вводим наши элементы пока не кончатся элементы н
    Node * cur = new Node(); //создаем значения в новом ноде
    cur -> val = x; //значения нодов будет наш х
 

    //проходим по условиям определить путь 
    if (i == 1) {
      head = tail = cur; //если 1 то все равно голове (первому)
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cin >> k; //вводим какое число надо найти 
  search(head, k); //проходит поиск какие числа ближе к этому числу
  return 0;
}