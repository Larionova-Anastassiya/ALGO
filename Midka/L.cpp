#include <iostream>
#include <queue>
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

    }
   
};



Node* insert(Node* root, int value){  //insert values function
    if(!root){
        return new Node(value);
    }

    if(root->value < value){
        root->right = insert(root->right, value);
    }

    else{
        root->left = insert(root->left, value);
    }

    return root;
}



void ordered(Node* root){ //function for answer

    if(!root){
        return;
    }


    ordered(root->left);

    if(!root->left && !root->right){
        answer++;
    }


    ordered(root->right);
}



int main(){
    Node* head;

    int n;
    cin >> n; //size operations
    
    int x;
    cin >> x; //values


    head = insert(head, x); //add in function where

    for(int i = 1; i < n; i++){
        cin >> x; //new values add
        insert(head, x);
    }

    ordered(head);
    
    cout << answer;
}