#include<bits/stdc++.h>
using namespace std;

//use heap struct, but can not use struct
struct Heap {
	vector<int> heap; //where save values for maximum


	int parent(int index) {
		return (index - 1) / 2;
	}
	int left(int index) {
		return 2 * index + 1;
	}
	int right(int index) {
		return 2 * index + 2;
	}


	void insert_val(int values_heap) {

		this->heap.push_back(values_heap);

		int index = this->heap.size() - 1; //for while and all values see


		while (index != 0 && this->heap[parent(index)] < this->heap[index]) {

			swap(this->heap[parent(index)], this->heap[index]);
			index = parent(index);

		}
	}



	int MAXIMUM() {
		//find maximum
		if (this->heap.size() == 0) 
			return INT_MAX;


		if (this->heap.size() == 1) {

			int root = this->heap[0];
			this->heap.pop_back();
			return root;

		}


		//update values next
		int root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);


		return root;
	}



	//basic for heap
	void heapify(int index) {
		
		int minimum = index;
		int l = this->left(index);
		int r = this->right(index);


		//conditions

		if (l < this->heap.size() && this->heap[l] > this->heap[minimum])
			minimum = l;

		if (r < this->heap.size() && this->heap[r] > this->heap[minimum])
			minimum = r;



		if (minimum != index) {

			swap(this->heap[index], this->heap[minimum]);
			this->heapify(minimum);

		}
	}


	/*
	//Basic functions Heap sorting
	void heapSort(int i[], int size){

		for (int i = (size - 1) / 2; i >= 0; i--) {
			heapify(i, size, i);
		}


		for (int i = size - 1; i >= 0; i--) {
			swap(i[0], i[i]);
			heapify(i, i, 0);
		}
	}	
	*/


	//all delete
    void remove(){
        heap.clear();
    }

};

    

/*
Input
4 3
1 2 3
4 5 6
6 7 8
9 8 7
Output
9 8 8 
6 7 7 
4 5 6 
1 2 3 
*/

int main(){ 

	Heap heap; 


    int n, r; 
	cin >> n >> r;  //size matrix
     

    int array[n][r]; //this matrix


	//insert values in matrix
    for(int i = 0; i < n; i++) {
        for(int l = 0; l< r; l++) {
            cin >> array[i][l];
        }
    }


    int new_array[n][r];

	//insert values in matrix new for answers
    for(int l = 0; l < r; l++){ 

        heap.remove();

        for (int index = 0; index < n; index++) { 
            heap.insert_val(array[index][l]);
        } 

        for(int index = 0; index < n; index++) {
            new_array[index][l] = heap.MAXIMUM();
        }
    } 

	//output answers sorting matrix
    for(int i = 0; i < n; i++) {

        for(int l = 0; l < r; l++) {
            cout <<  new_array[i][l] << " ";
        }

        cout << endl;
    }
}