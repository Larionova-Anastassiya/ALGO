#include <bits/stdc++.h>

using namespace std;

//ноды поддерева показать
class BST {
    //приватные методы
private:

    struct Node{
    //объявляем ноду где храниться будет
        Node(int x) {
            value = x; //дефолтное значение это х
        }

        int value; //имеет значение и пути нод слева и справа
        Node *left = NULL;
        Node *right = NULL;
    };

    Node *root = NULL; //самая верхушка

    //добавлять элементы в ноды 
    void add(Node *node, int x) {
        // налево
        if(node->value > x) {
            if (node->left)
                add(node->left, x);
            else
                node->left = new Node(x); //новая нода если ее нет
        } else { //направо
            if(node->right)
                add(node->right, x);
            else
                node->right = new Node(x);
        }
    }

    //Показать ноду начиная с основы
    void showXNode(Node *node, int x, bool used) {
        //если нет нод
        if(!node)
            return ;
            //если встретили ноду
        if(node->value == x)
            used = true;
        if(used)
            cout << node->value << " "; //если встретили ноду вывели ее

            //сдвиги для пробега по всем
        showXNode(node->left, x, used);
        showXNode(node->right, x, used);
    }

//публичные метода используя приватные
public:

    void add(int x) { //добавить значение х
        if(!root) //если нет нод то создать
            root = new Node(x);
        else
            add(root, x); //добавить из приват значение
    }

    void showXNode(int x) { //получить ноду указанную нами
        showXNode(root, x, false);
    }

};

//основной код
int main() {

    BST bst; //объявляем дерево новое

    int n;
    cin >> n; //вводим значение сколько
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        bst.add(x); //вводим значения добавляя 
    }

    int x;
    cin >> x; //вводим ноду какой узнать
    bst.showXNode(x); //вывод результата


    return 0;
}