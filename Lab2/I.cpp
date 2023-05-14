#include <iostream>
#include <iterator>
  
using namespace std;

//создаем ноды dublе list со значениями и путями следющих нод (с двух сторон может работать) 
struct Node{
	Node * prev; //прошлое значение
	Node * next; //следующее значение
	string val;
	Node(string valempty = ""){ //если пустое будет то все пустые
		prev = NULL;
		next = NULL;
		val = valempty;
	}	
};


// вызвали голову и хвост как пустотой
Node * head = NULL;
Node * tail = NULL;
int cnt; //наш счетчик

//функция добавления с конец
void add_back(string s){
    Node * cur = new Node(s); //новую ноду делаем
    if(head == NULL){ //если голова пуста то обьявлем значение головой
        head = cur;
        tail = cur;
    }
    else{
        tail->next = cur->prev; //хвост получаем иначе
        tail = cur;
    }
}

//функция добавления в начало
void add_front(string s){
    Node * cur = new Node(s); //новая нода
    if(head == NULL){ //если пустая то равны ей
        head = cur;
        tail = cur;
    }
    else{
        cur->next = head; //иначе мы получаем голову
        head = cur;
    }
}

//проверка если все пустое и голова и хвост не существует
bool empty(){
    if(head==NULL && tail==NULL)
        return true;
    return false;
}


//функция удалить с начала значение (голову меняем на следующее а прошлое делаем пустым)
void erase_front(){
    Node * temp = head;
    head = head->next;
    temp = NULL;
}


//функция удаления с конца (хвост меняем на предыдущее значение а прошлое значение пустым)
void erase_back(){
    Node * temp = tail;
    tail = tail->prev;
    temp = NULL;
}


//вызывать значение первого значения (головы)
string front(){
    return head->val;
}

//вызывать значение последнего значения (хвоста) показать его
string back(){
    return tail->val;
}

//функция если очистить весь лист
void clear(){
    while(head != NULL){ //пока не станет голова пустой каждый элемент делаем пустым
        Node * temp = head;
        head = head->next;
        temp = NULL;
    }
    tail = NULL; //хвост сразу определяем пустым
}
  

//главная наша работа по добавлению и проверке функций
int main(){
	string s; //обьявляем строку
   	while(cin >> s){ //вводим строку (что нужно выполнить)
   		if(s == "add_front"){ //добавить сначала
   			string t;
   			cin >> t; //вводим строку что добавить
   			add_front(t); //добавляем по функции
   			cout << "ok" << endl; //вывод если выполнил
   		}

   		if(s == "add_back"){ //добавить в конец
   			string t;
   			cin >> t; //вводим что добавить
   			add_back(t); //добавляем
   			cout << "ok" << endl; //выводим если добавил
   		}

   		if(s == "erase_front"){ //удалить начальное
   			if(empty()){ //если там пусто то выведет слово ошибка
   				cout << "error" << endl;
   			} else{
   				cout << front() << endl; //выведет название которое удаляет после чего удалит
   				erase_front();
   			}
   		}

   		if(s == "erase_back"){ //удалить с конца
   			if(empty()){ //если пустой то выведет слово ошибки
   				cout << "error" << endl;
   			} else{
   				cout << back() << endl; //выведет наше значение последнее и удалит
   				erase_back();
   			}
   		}

   		if(s == "front"){ //показать значение первое
   			if(empty()){ //если пустое то ошибка
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl; //покажет первое значение
   			}
   		}
   		if(s == "back"){ //показать значение последнего
   			if(empty()){ //если пустое то ошибка
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl; //покажет последнее значение
   			}
   		}

   		if(s == "clear"){ //очистить весь лист
   			clear(); //очистит
   			cout << "ok" << endl; //выведет если удалил
   		}

   		if(s == "exit"){ //выход из функций
   			cout << "goodbye" << endl; //выведет и закончит цикл
   			break;
   		}
   		
   	}
    return 0;
}