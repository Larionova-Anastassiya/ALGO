#include<bits/stdc++.h>
using namespace std;

//Use LINKED LIST

int triangles[10000];



//create node for list
struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};




//insert in node (basic)
Node* insert(Node* root, int val){
    if(!root){
        return new Node(val);
    }

    if(root->val < val){
        root->right = insert(root->right, val);
    }

    else{
        root->left = insert(root->left, val);
    }

    return root;
}


//Specific for task

void answers(Node* cur){

    if(!cur){
        return;
    }

    answers(cur->left);
    int l = 0, r = 0;
    Node* left_part = cur;
    Node* right_part = cur;


    while(left_part){
        left_part = left_part->left;
        l++;
    }

    
    while(right_part){
        right_part = right_part->right;
        r++;
    }

    int value = min(l, r);

    //answers triangles

    if(value > 1){
        for(int i = 0; i < value-1; i++){
            triangles[i]++;
        }
    }


    answers(cur->right);
}


//TRIANGLES
/*
Input
5
5 2 6 8 1
Output
1 1 0 0 
*/

int main(){
    Node* root;
    int n;
    cin >> n;


    int value;
    cin >> value;


    root = insert(root, value); //root node (first element)

    //values next root:
    for(int i = 1; i < n; i++){
        cin >> value;
        insert(root, value);
    }


    answers(root);


    for(int i = 0; i < n-1; i++){
        cout << triangles[i] << ' ';
    }
}