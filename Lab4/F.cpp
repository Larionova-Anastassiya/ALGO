#include <bits/stdc++.h>

using namespace std;

/*
самый маленький Triangle у нас будет просто 3 ноды

Назовем ее просто node. И есть 2 ноды рядом.
Это node->left, node-right.

Их надо посчитать
*/


class BST {
    //приватные методы
private:

    struct Node{ //объявляем ноду где храниться будет

        Node(int x) {
            value = x; //дефолтное значение это х
        }

        int value; //имеет значение и пути нод слева и справа
        Node *left = NULL;
        Node *right = NULL;
    };

    Node *root = NULL; //самая верхушка


    //добавлять элементы в ноды как обычное дерево (слева наименьшее справа большее чем родительское)
    void add(Node *node, int x) {
        if(node->value > x) {
            if (node->left)
                add(node->left, x);
            else
                node->left = new Node(x);
        } else {
            if(node->right)
                add(node->right, x);
            else
                node->right = new Node(x);
        }
    }

 
    //посчитает мини деревья правильные  счетчиком
    int getMinTriangleCount(Node *node) {
        if(!node)
            return 0;
        return (node && node->left && node->right) + getMinTriangleCount(node->left) + getMinTriangleCount(node->right);
    }


//публичные метода используя приватные
public:
    //добавить значение х
    void add(int x) {
        //если нет верхушки то объявит ее
        if(!root)
            root = new Node(x);
        else
            add(root, x); //добавить из приват значение
    }

    //вернет нам значение подсчитав треугольники
    int getMinTriangleCount() {
        return getMinTriangleCount(root);
    }

};


//основной код
int main() {

    BST bst; //объявляем дерево новое

    int n;
    cin >> n; //вводим значение сколько
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x; //вводим значения добавляя в основное дерево
        bst.add(x);
    }

    cout << bst.getMinTriangleCount(); //вернет количество наших мини деревьев в основном



    return 0;
}