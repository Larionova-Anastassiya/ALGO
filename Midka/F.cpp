#include <iostream>
using namespace std;

int answer = 0; //global value

//create node for Linked list
struct Node{
    int value;

    Node* left;
    Node* right;


    int level; //values in task

    Node(int value){ //first if only value
        this->value = value;
        left = right = NULL;

        level = 0;
    }

    Node(int value, int level){
        this->value = value;
        this->level = level;

        left = right = NULL;
    }
};



Node* insert(Node* root, int value, int level){  //insert values function
    if(!root){
        return new Node(value, level);
    }

    if(root->value < value){
        root->right = insert(root->right, value, level+1);
    }

    else{
        root->left = insert(root->left, value, level+1);
    }

    return root;
}



void ordered(Node* root){ //function for answer

    if(!root){
        return;
    }

    ordered(root->left);
    
    answer += root->value - root->level;
    ordered(root->right);
}



int main(){
    Node* head;

    int n;
    cin >> n; //size operations
    
    int x;
    cin >> x; //values


    head = insert(head, x, 0); //add in function where

    for(int i = 1; i < n; i++){
        cin >> x; //new values add
        insert(head, x, 0);
    }


    ordered(head);
    cout << answer;
}