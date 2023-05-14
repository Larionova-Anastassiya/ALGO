#include<bits/stdc++.h>
using namespace std;

class Heap {
    
    //private values
    int size;
    vector<int> vect;


    public:

        Heap() {
            size = 0;
        }
    //basic function:
        void insert(int val) {
            size++;

            if (vect.size() < size) {
                vect.push_back(val);
            }

            vect[size - 1] = val;
            shiftUp(size - 1);
        }


        void shiftUp(int i) {
            if (i == 0) 
                return;

            int p = (i - 1) / 2;

            if (vect[i] > vect[p]) {
                swap(vect[i], vect[p]);
                shiftUp(p);  
            }
        }


        void shiftDown(int i) {
            if (i < size) {
                int swapId = i;
                int l = (i * 2) + 1;
                int r = (i * 2) + 2;

                if (l < size && vect[l] > vect[swapId]) 
                    swapId = l;
                

                if (r < size && vect[r] > vect[swapId]) 
                    swapId = r;
                

                if (swapId != i) {
                    swap(vect[i], vect[swapId]);
                    shiftDown(swapId);
                }
            }
        }


        //specific for TASK 
        void solve(int i, int data) {
            i = i - 1;
            vect[i] = vect[i] + data;
            int num = vect[i];

            shiftUp(i);
            
            int j = getIndex(num);

            cout << j << endl;
        }


        int getIndex(int data) {

            for (int i = 0; i < size; i++) {

                if (vect[i] == data) {
                    return i + 1;
                }

            }

        };


        int extractMax() {
            int maxNum = vect[0];

            swap(vect[0], vect[size - 1]);

            size--;
            shiftDown(0);
            return maxNum;
        } 

        void print() {
            for (int i = 0; i < size; i++) {
                cout << vect[i] << " ";
            }
        }
        
};



//TRIANGLES
/*
Input
5
5 2 6 8 1
Output
1 1 0 0 
*/


int main() {
    Heap heap;
    int n; 
    cin >> n;

    //values:
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        heap.insert(x);
    }


    int q; 
    cin >> q;


    while(q != 0) {
        q--;
        int index; 
        int key;
        cin >> index >> key;
        heap.solve(index, key);
    }
   

   heap.print(); //output answer
}