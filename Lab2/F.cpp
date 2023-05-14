//вставить число по индексу в другое место
#include <iostream>
using namespace std;

struct Node{
	//наши числа и обьявление следующей ноды
	int val;
	Node * next;

	//если все пусто то будет 0 и нул
	Node(){
		this->val = 0;
		this->next = NULL; 
	}
 
	//если введем число то рано числу и следующее пустое
	Node(int val){
		this->val = val;
		this->next = NULL;
	}

	//вводим число и следующей ноды место
	Node(int val, Node * next){
		this->val = val;
		this->next = next;
	}
};


//создаем лист где все хранится
struct LinkedList{
	int size; //размер чтобы знать куда помещать
	Node * head;
	Node * tail;

	LinkedList(){
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	//добавление значений в начало
	void pushFront(int val){
		this->size++; //увеличиваем размер при работе
		Node * temp = new Node(val);
		if (this->head == NULL){ //если голова пуста то это будет нашей головой
			this->head = temp;
			this->tail = temp; 
		} else{ //иначе добавляем следующий элемент и это будет головой
			temp->next = this->head;
			this->head = temp;
		}
	}

	//добавляем в конец
    void pushBack(int val){
		this->size++; //увеличиваем размер
		Node * temp = new Node(val);
		if (this->head == NULL){ //если пустое то это будет нашей головой
			this->head = temp;
			this->tail = temp;
		} else{ //иначе следующий элемент просто будет
			this->tail->next = temp;
			this->tail = temp;
		}
	}

	//добавляем индексы для знания элементов и добавит число куда надо
	void addIndex(int index, int val){
		if (index > this->size){ //если индекс больше размера то возвращаем
			return;
		} else if (index == 0){
			this->pushFront(val); // если 0 то добавляем в начало и делаем головой
		} else if (index == this->size){ //если индекс равен размеру то добавляем в конец значения
			this->pushBack(val);
		} else{
            this->size++; //увеличиваем размер и добавляем значения
			Node * temp = new Node(val);
			Node * cur = this->head;
			for (int i = 1; i < index; i++){
				cur = cur->next; //будет проходить по всем элементам подряд
			}
			temp->next = cur->next;
			cur->next = temp;
		}
	}

	//вывод наших значений
	void printLL() {
		Node * cur = this->head;
		while (cur != NULL) { //пока не будет пустотой
			cout << cur->val << " "; //будет выводить значения пробега и дальше идти
			cur = cur->next;
		}
		cout << endl;
	}
};


//основное решение и добавление через терминал
int main(){
	int n;
    cin >> n; //вводим сколько чисел в листе
    LinkedList list;
    while (n--){ //пока не кончится н будем вводить числа
        int val;
        cin >> val;
        list.pushBack(val); //добавлять значения в конец листа
    }
    int c, index; //вводим число которое надо вставить и индекс куда
    cin >> c;
    cin >> index;

    list.addIndex(index, c); //по индексу определяет число куда надо
    list.printLL(); //выведет наше число уже в новом листе

	return 0;
}