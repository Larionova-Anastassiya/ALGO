#include <iostream>
using namespace std;


struct Node {
	int data, cnt;

	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
        cnt = 1;
		left = NULL;
		right = NULL;
	} 
};

Node* getMin(Node* root) {
	while (root->left != NULL) {
		root = root->left;
	}

	return root;
}

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	}else if (root->data == data){
        root->cnt++;
    } else if (root->data > data) {
		root->left = add(root->left, data);
	} else if (root->data < data) {
		root->right = add(root->right, data);
	}

	return root;
}

Node* deleteNode(Node* root, int data) {

	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
        
        if (root->cnt > 1){
            root->cnt--;
            return root;
        }
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
            root->cnt = temp->cnt;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

Node* find(Node* root, int x) {

	if (root == NULL) {
		return NULL;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}


int main(){

    long long  n, x;
    char q[20];
    cin>>n;

    Node *root = NULL;

    while(n--){
        cin>>q>>x;

        if (q[0] == 'i') {
            root = add(root, x);
        }

        else if (q[0] == 'c'){
            Node *ans = find(root, x);
            cout << (ans ? ans->cnt : 0) << '\n';
        }
        
        else if (q[0] == 'd') {
            root = deleteNode(root, x);
        }
        
    }
    return 0;
}