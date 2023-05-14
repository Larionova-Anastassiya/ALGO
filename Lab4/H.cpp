#include <bits/stdc++.h>

using namespace std;
/*
Замените ключ каждого узла суммой ключей по узлам, у которых ключ больше или равен. 
Печатайте новые ключи в порядке возрастания.
*/
class BST {
    //приватные методы
private:
    vector<int> res;
    int curSum = 0;

  //объявляем ноду где храниться будет
    struct Node{
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
        if(node->value > x)  {  // налево
            if (node->left) 
                add(node->left, x);
            else
                node->left = new Node(x); //новая нода если ее нет
        } else { //направо
            if(node->right)
                add(node->right, x);
            else
                node->right = new Node(x); //новая нода если ее нет
        }
    }

    //результат суммы всех нод справа налево
    void getSums(Node *node) {
        //если пустое
        if(!node)
            return;

        getSums(node->right); //берет правой первой
        curSum += node->value; //получает данные
        res.push_back(curSum); //добавляет результат в наш вектор
        getSums(node->left); //берет левой
    }

//публичные метода используя приватные
public:

    void add(int x) {  //добавить значение х
        if(!root) //если нет нод то создать
            root = new Node(x);
        else
            add(root, x); //добавить из приват значение
    }

    vector<int> getSums() { //получить сумму
        getSums(root);
        return res; //получить результат
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

    vector<int> res = bst.getSums(); //вводим вектор значений сумм
    for(int i : res)
        cout << i << " "; //выводим результат вектора ответа


    return 0;
}
