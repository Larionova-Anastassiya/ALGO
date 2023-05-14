#include <bits/stdc++.h>

using namespace std;

class BST {

//приватные методы
private:

    //объявляем ноду где храниться будет
    struct Node{
        Node(int x) { //дефолтное значение это х
            value = x;
        }
        int value; //имеет значение и пути нод слева и справа
        Node * left = NULL;
        Node * right = NULL;
    };

    Node * root = NULL; //самая верхушка


    //добавлять элементы в ноды
    void add(Node *node, int x) {

        //если значение наше больше то добавит слева
        if(node->value > x) {
            if (node->left)
                add(node->left, x);
            else
                node->left = new Node(x);
        } else { //иначе добавит большее число справа
            if(node->right)
                add(node->right, x);
            else
                node->right = new Node(x);
        }
    }


    //проверить есть ли путь
    bool path(string &s, Node *node, int pos) {
        //если нода пустая
        if(!node)
            return false;

        //если когда путь есть
        if(pos == s.size())
            return true;

            //если втретит букву Л то проверит есть ли путь влево если сдвинуть и  дойти дальше
        if(s[pos] == 'L')
            return path(s, node->left, pos + 1);
        return path(s, node->right, pos + 1); //если буква Р то вправо путь
    }


//публичное уже
public:

    //добавить значение х
    void add(int x) {
        //если нет верхушки то добавить
        if(!root)
            root = new Node(x);
        //иначе добавить из приват значение
        else
            add(root, x);
    }

    bool path(string &s) { //проверка есть ли путь или нет
        return path(s, root, 0); //проверка по приватному
    }

};


//основной код
int main() {
    BST bst; //объявляем дерево новое

    int n, m;
    cin >> n >> m; //вводим значение сколько чисел и сколько запросов путей
    for(int i = 0 ; i < n; i++) {
        int x;
        cin >> x;
        bst.add(x); //вводим значения добавляя (из паблик)
    }

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s; //добавляем строки Л и Р путей
        cout << (bst.path(s) ? "YES" : "NO") << endl; //если проверка пройдет то Да выведет
    }

    return 0;
}
