// сдвинуть все слова на определенное количество раз
#include<iostream>
using namespace std;

struct Node{
	//объявляем наше значение и следующее положение
	string word;
	Node *next;

	//условия если пустой, если ввели только слово, и следующее значение по месту
	Node(){
		this->word = "";
		this->next = NULL; //означает что это пустой следующий
	}
	Node(string word){
		this->word = word;
		this->next = NULL;
	}
	Node(string word, Node *next){
		this->word = word;
		this->next = next;
	}
};

//создание листа где все хранится
struct LinkedList{
	int size; //размер и данные объявляем
	Node * head;
	Node * tail;

	LinkedList(){ //дефолтные пустые значения
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	//добавить значение в начало
	void pushFront(string word){
		this->size++;
		Node * temp = new Node(word);
		if (this->head == NULL){ //объявление головы если ее еще нет
			this->head = temp;
			this->tail = temp;
		} else{
			temp->next = this->head;//следующие элементы и их места
			this->head = temp;
		}
	}

    //добавить значения в конец
	void pushBack(string word){
		this->size++;
		Node * temp = new Node(word);
		if (this->head == NULL) {
			this->head = temp;
			this->tail = temp;
		} else{
			this->tail->next = temp;
			this->tail = temp;
		}
	}


    //Изменяет индекс слов
    void change(int index){ 
        Node *temp = this->head;
        for(int i = 0; i < index; i++){
            this->pushBack(temp->word);
            temp = temp->next;
        }
        this->head = temp;
    }

	//вывод данных
    void print(){
        Node * cur = this->head;
        while (cur != NULL) { //пока не пустое будет показывать слова
            cout << cur->word << " ";
            cur = cur->next;
        }
        cout << endl;
    }

};


//главное действие
int main(){
    int n, c; //вводим сколько слов будет и на сколько сдвинуть
    cin >> n >> c;
    LinkedList list;
    for(int i = 0; i < n; i++){ //проходит по всем словам
        string word;
        cin >> word; //добавляет слова в начало оставшиеся (сдвиг на начало уходит)
        list.pushBack(word);
    }
    list.change(c);
    
    list.print(); //показывает результат
}

