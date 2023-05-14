#include <bits/stdc++.h>

using namespace std;

 // вернуть максимальную ширину
class BST {

    //приватные методы
private:
    vector<int> level; //вектор данных 

    //объявляем ноду где храниться будет
    struct Node{
        Node(int x) {
            value = x; //дефолтное значение это х
        }

        int value; //имеет значение и пути нод слева и справа
        Node *left = NULL;
        Node *right = NULL;
    };

    Node *root = new Node(1); //самая верхушка новая 1 нода



    //добавлять элементы в ноды по местонахождениям и условиям
    void add(Node *node, int x, int y, int z) {

        if(!node) //если ее нет
            return;

        //Находим нужную вершину методом обхода.
        //Если слева нужно то на лево повесить иначе же направо.
        if(node->value == x) {
            if(z) {
                node->right = new Node(y);
            }
            else {
                node->left = new Node(y);
            }
            return;
        }

        //выполняем добавление дальше по нодам
        add(node->right, x, y, z);
        add(node->left, x, y, z);

    }


    //расчитать глубину
    int depth(Node *node) {
        //если пустой
        if(!node)
            return 0;

            // выполнение нахождения для расчета ширины
            //Если с лева у нас дерево длиннее (размер имеет значение) то берем ее значение иначе же 
            //справа будет правильным выбором.
        return max(depth(node->left), depth(node->right)) + 1;
    }


    //считать сколько раз мы были на этой глубине
    void dfs(Node *node, int x) {
        //если пустой
        if(!node)
            return;

        level[x]++;
        dfs(node->right, x+1);
        dfs(node->left, x+1);
    }



//публичные метода используя приватные
public:
    //добавить значение х
    void add(int x, int y, int z) {
        add(root, x, y, z); //добавить из приват значение
    }

    //дать результат ширины
    int getWeight() {
        level = vector<int>(depth(root)+1, 0);
        dfs(root, 0);
        return (*max_element(level.begin(), level.end())); //максимальный элемент ответ
    }

};



//основной код
int main() {

    BST bst; //объявляем дерево новое

    int n;
    cin >> n; //вводим значение сколько деревьев 
    for(int i = 1 ; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;  //вводим значения (3 значения) добавляя (из паблик)
        bst.add(x, y, z);
    }

    /*
    описание бинарного дерева, означающее, что вершина y сын вершины x, 
    если z = 0, это левый сын, 
    если z = 1, это правый сын.

    
    6
    1 2 1
    1 3 0
    3 5 0
    3 6 1
    2 4 1
    */


    cout << bst.getWeight(); //выведет ответ нашей большей ширины


    return 0;
}
