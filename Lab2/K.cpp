#include <iostream>

using namespace std;

 //создаем ноды
struct Node{
    //объявляем наше значение и следующее положение
    string val;
    Node * next;
    bool ok;
    string ans;

    //если ввели только слово следующее пустое
    Node(string val){
        this->val = val;
        next = NULL;
        ok = true;
    }
};

 //проводит поиск по голове и сейчас ноды
string search(Node * head, Node * now){
    Node * cur = head;
    while(cur != now->next){  //пока не равно последней нашей ноде
        if(cur->ok) { //пока правдиво возвращает значения
            return cur->val;
        }
        cur = cur->next; //потом идет на следующий элемент
    }
    return "-1"; //если они равны то выведет -1
}

//добавлять наши значения функция
Node * push(Node * head, string val){
    Node * newNode = new Node(val);
    if(head == NULL){ //если пустая голова то это будет головой
        head = newNode;
        head->ans = head->val; 
    } else{
        Node * cur = head;
        while(cur != NULL){ //пока значение пробега не пустой будет выполнять
            if(cur->val == newNode->val){ //если значения их равны то закончится работа и будет ложь
                cur->ok = false;
                newNode->ok = false;
            }if(cur->next == NULL){ //если пустота то добавит новое значение и проведет поиск по голове
                cur->next = newNode;
                newNode->ans = search(head, newNode);
                break;
            }
            cur = cur->next; //пойдет по следующий элемент
        }
    }
    return head; //вернет голову
}


//функция вывода
void print(Node * head){
    Node * cur = head; 
    while(cur != NULL){ //пока не ноль будет выводить результат ответа поиска и пойдет к следующим
        cout << cur->ans << " ";
        cur = cur->next;
    }
    cout << endl;
}

//основное действие
int main(){
    int n;
    cin >> n; //вводим сколько всего листов значений
    Node* head = NULL;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t; //вводим сколько будет в одном листе значений
        for(int j = 0; j < t; j++){
            string val;
            cin >> val; //вводим значения уже в лист
            head = push(head, val); //добавляет в лист и проводит там поиск
        }
        print(head); //выводит голову и делает ее пустой (первый неповторяющийся элемент для каждого нового символа)
        head = NULL;
    }
    return 0;
}