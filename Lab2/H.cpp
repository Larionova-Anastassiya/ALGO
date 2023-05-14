#include <iostream>
using namespace std;

//код взят с сайта и дополнен уже функциями
int removed, sz;
 
struct Node{
    //объявляем наше значение и следующее положение
    int val;
    Node* next;
    //условия если пустой, если ввели только значение, и следующее значение по месту, если оба ввели (2 вид обьявления)
    /*
    все значения можно записать так:
    Node(){
		this->val = 0;
		this->next = NULL; //означает что это пустой следующий
	}
    */
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(Node * next): val(0), next(next) {}
    Node(int x, Node * next): val(x), next(next) {}
};
 

//функция вставлять в ноды по условиям обьявляя головы и возвращаяя первое
Node * insert(Node * head, Node * node, int p) {
    if(p > 1) insert(head->next, node, p - 1);
    else if(p) {
        node->next = head->next;
        head->next = node;
    }else {
        node->next = head;
        head = node;
    }
    return head;
}
 
//удалить значение в ноде так же по условиям (удаляет по голове постепенно смещая)
Node * remove(Node * head, int p) {
    if(p > 1) remove(head->next, p - 1);
    else if(p) {
        removed = head->next->val;
        head->next = head->next->next;
    }
    else {
        removed = head->val;
        head = head->next;
    }
    return head;
}
 

//заменит значения удаляя один и вставляя туда новое
Node * replace(Node* head, int p1, int p2) {
    head = remove(head, p1);
    head = insert(head, new Node(removed), p2);
    return head;
}
 

//развернем лист с помощью головы и хвоста
Node * reverse(Node* head) {
    Node * prev = NULL, * cur = NULL, * next = NULL;
    cur = head;
    while(cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev; //голова становится предыдущий элемент и так постепенно
    return head;
}
 
//функция вывода значений головы постепенно смещая
void print(Node * head) {
    if(!head) return;
    cout << head->val << " ";
    print(head->next);
}
 

//циклически влево
Node * cyclic_left(Node * head, int x) {
    x = x % sz; //наши данные 
    if(x == sz || x == 0) return head;
    Node * copy_head = head, * cur = new Node();
    cur->next = head;
    while(cur->next) cur = cur->next; //следующий элемент
    for(int m = 0; m < x; m++) {
        cur->next = new Node(copy_head->val);
        copy_head = copy_head->next; //копирует и сдвигает
        cur = cur->next;
    }
    for(int w = 0; w < x; w++) head = head->next; //голова будет значит следующий элемент
    return head;
}
 

//циклически вправо (вызывает налево но меняет траекторию значений)
Node * cyclic_right(Node * head, int x) {
    return cyclic_left(head, sz - x);
}
 
//главная работа выполнения (код взят с сайта и дополнен)
int main(){
    //cin.tie(0);
    //cout.tie(0);
    Node * head = nullptr;
    while(true) {
          int command; cin >> command;
           if(command == 0) break;
           else if(command == 1) { //по команде надо добавить
               int x, p;
               cin >> x >> p;
               head = insert(head, new Node(x), p);
                ++sz;
            } else if(command == 2) { //по команде надо удалить
                int p;
                cin >> p;
                head = remove(head, p);
               --sz;
            }else if(command == 3) { //по команде надо показать верхушку
             print(head);
              cout << "\n";
            }else if(command == 4) { //по команде надо заменить определенные данные
                int p1, p2;
                cin >> p1 >> p2;
                head = replace(head, p1, p2);
            }else if(command == 5) head = reverse(head); //по команде надо развернуть
            else if(command == 6) { //по команде сдвиг влево
                int x;
                cin >> x;
                head = cyclic_left(head, x);
            }else if(command == 7) { //по команде сдвиг вправо
                int x;
                cin >> x;
                head = cyclic_right(head, x);
            }
    }
    return 0;
}