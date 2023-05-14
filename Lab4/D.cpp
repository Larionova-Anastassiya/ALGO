#include <bits/stdc++.h>
using namespace std;


struct Node {
    int val;
    Node*left;
    Node*right;

    Node(int val) {
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};

int t;

class BST{
    Node * root;
    
    Node * push(Node * cur, int val) {
        if(cur==nullptr) {
            return new Node(val);
        }
        if(val < cur->val) cur->left = push(cur->left, val);
        if(val > cur->val) cur->right = push(cur->right, val);
        return cur;
    }


    void inOrder(Node * cur) {
        if(cur->left) inOrder(cur->left);
        if(cur->right) inOrder(cur->right);
    }

    void search(int t, Node * cur, Node * &target) {
        if(cur && !target) {
            if(cur -> val == t) target = cur;
            if(cur -> val < t) search(t, cur -> right, target);
            if(cur -> val > t) search(t, cur -> left, target);
        }
    }


    int Height(Node * cur) {
        if(cur -> left ==nullptr && cur -> right == nullptr) {
            return 0;
        }
        int left = 0;
        if( cur -> left != nullptr) {
            left = Height(cur -> left);
        }
        int right = 0;
        if(cur -> right != nullptr) {
            right = Height(cur -> right);
        }
        return (max(left, right) + 1);
    }

    int Sum(Node * cur, int level, int sum[]) {
        if(cur == nullptr) {
            return 0;
        }
        sum[level] += cur -> val;
        Sum(cur -> left, level + 1, sum);
        Sum(cur -> right, level + 1, sum);
    }



public:
    BST(){
        root=nullptr;
    }

    void search(int t) {
        Node * target =nullptr;
        search(t, root, target);
        inOrder(target);
    }

    void push(int val) {
        root=push(root, val);
    }

    
    int Height() {
        return Height(root);
    }


    void Sum() {
        int levels = Height(root) + 1;
        int sum[levels] = {0};
        Sum(root, 0, sum);
        printArr(sum, levels);
    }


    void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    }
};


int main() {

    BST tree;
    int n;
    cin>>n;


    while(n--) {
        int x;
        cin>>x;
        tree.push(x);
    }

    
    cout<<tree.Height() + 1<<'\n';
    tree.Sum();
}