#include<iostream>
using namespace std;

//объявляем наши ноды
struct Node{
    int val; //значение цифры и след знает где
    Node * next;

    //различные условия если ничего не добавили и если один, если все
    Node(){ //дефолтные значения 0 и следующий пусто
        this->val = 0;
        this->next = NULL;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
    Node(int val, Node *next){
        this->val = val;
        this->next = next;
    }
};


//выполняем какие либо действия
struct LinkedList{
    int size; //размер
	Node * head;

	LinkedList(){
		this->size = 0;
		this->head = NULL;
	}


    //функция добавления данных
	void push(int val){
		this->size++; //каждый раз увеличиваем размер
		Node * temp = new Node(val);
		if (this->head == NULL){
			this->head = temp; //если нет головы первой то равна этой голове первое значение
		}
		else{
			temp->next = this->head;
			this->head = temp;
		}
	}

    //функция поиска максимальной суммы всех чисел
	void findMaxSum() { 
        Node * cur = this->head; 
        int sum = 0, mx = -1000000000; //данные для дальнейшего пользования
        while (cur != NULL) {  //пока не пусто будет выполняться
            sum += cur->val;  //складывает наши данные

            if (sum<cur->val){  //если сумма меньше (начальная 0) то равна этой сумме
                sum=cur->val; 
            } 

            mx=max(sum, mx); //находим максимум с помощью встроенной между суммой и максимум (самое маленькое число)
            cur = cur->next; 
        } 
        cout << mx; //выводим наш максимум
    }
};


//главная работа для добавления
int main(){
    int n;
    cin >> n; //вводим сколько всего чисел
    LinkedList list;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a; //добавляем числа пока можем
        list.push(a); //добавляет в лист их 
        
    }
    list.findMaxSum(); //выполняет функцию поиска максимума и вернет результат
}