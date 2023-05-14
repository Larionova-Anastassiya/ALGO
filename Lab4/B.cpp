#include <bits/stdc++.h>

using namespace std;

// сколько же node у нас есть в поддереве
class Bst {
    //приватные методы
private:

    //объявляем ноду где храниться будет
    struct Node{
        Node(int x) {
            value = x; //дефолтное значение это х
        }

        int value; //имеет значение и пути нод слева и справа
        Node *left = nullptr;
        Node *right = nullptr;
    };

    Node *root = nullptr; //самая верхушка


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

    //узнать размер нод
    int sizeOfNode(Node *node, int x, bool used) {
        //если нет нод
        if(!node)
            return 0;
        //если встретили ноду
        if(node->value == x)
            used = true;
        //пробегаться по всему и увеличивать (пробег справа и слева)
        return used + sizeOfNode(node->right, x, used) + sizeOfNode(node->left, x, used);
    }


//публичные метода используя приватные
public:

    void add(int x) { //добавить значение х
        if(!root) //если нет нод то создать
            root = new Node(x);
        else 
            add(root, x); //добавить из приват значение
    }

    int sizeOfNode(int x) { //получить размер
        return sizeOfNode(root, x, false);
    }

};


//основной код
int main() {

    Bst bst; //объявляем дерево новое

    int n;
    cin >> n; //вводим значение сколько
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        bst.add(x); //вводим значения добавляя 
    }

    int x;
    cin >> x; //вводим ноду какой узнать
    cout << bst.sizeOfNode(x); //вывод результата ее размера


    return 0;
}
