#include<iostream>
using namespace std;

struct Node{
	//наши числа и обьявление следующей ноды
	string name;
	Node * next;

	Node(){ //если все пусто то будет "" и нул
		this->name = "";
		this->next = NULL; 
	}
	Node(string name){ //если введем 1 и следующее пустое
		this->name = name;
		this->next = NULL;
	}
	Node(string name, Node * next){ //вводим  и следующей ноды место
		this->name = name;
		this->next = next;
	}
};

//создаем лист где все хранится
struct LinkedList{
	int size; //размер чтобы знать куда помещать
	Node *head;
	Node *tail;

	LinkedList(){
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	//добавляем в конец
    void pushback(string name){
		this->size++;
		Node * temp = new Node(name);
		if (this->head == NULL){ //если голова пуста то это будет нашей головой
			this->head = temp;
			this->tail = temp;
		} else{ //иначе следующий элемент просто будет
			this->tail->next = temp;
			this->tail = temp;
		}
	}

	//функция обратно развернуть
    void reverse(){
        // Инициализировать текущий, предыдущий и следующий указатели
        Node * current = this -> head;
        Node * prev = NULL, * next = NULL;
 
        while (current != NULL) { //пока не будет пустотой
            next = current->next;
            // Обратный указатель текущего узла
            current->next = prev;
            // Переместить указатели на одну позицию вперед
            prev = current;
            current = next;
        }
        head = prev;
    }

	//вывод наших значений
	void printLL() {
        cout<< "All in all: "<< this->size << endl; //размер покажет
        cout<< "Students:"<< endl;
		Node * cur = this->head;
        while (cur != NULL) { //пока не будет пустотой
            cout << cur->name << endl; //будет выводить значения пробега и дальше идти
            cur = cur->next;
        }
	}
};


//основное решение и добавление через терминал
int main(){
    int n;
    cin >> n; //вводим сколько в листе
    string name , copy;
    copy = "";
    LinkedList list;
    while(n--){ //пока не кончится н будем вводить
        cin >> name;
        if(name != copy){
            list.pushback(name); //будет добавлять слова пока не будет пустым
            copy = name;
        }
        else{
            continue;
        }
    }
    list.reverse(); //развернет все
    list.printLL(); //выведет наш ответ уже в новом листе

	return 0;
}