#include <iostream>
#include <set>
#include <vector>

using namespace std;

int k;

class Heap{
    long long a[1000005];
    long long size;
public:
    Heap(){
        a[0] = -2147483647;
        size = 0;
//        a[0] = 20000000000;
    }


    long long left(long long i){
        return i * 2;
    }

    long long right(long long i){
        return i * 2 + 1;
    }

    long long parent(long long i){
        return i / 2;
    }

    int sz(){
        return size;
    }


    void insert(long long val){
        if (size < k){
            size++;
            a[size] = val;
            sift_up(size);
        }
        else{
            if(a[1] < val){
                a[1] = val;
                sift_down(1);
            }
        }
    }


    void sift_up(int i){
        while (i > 1 && a[parent(i)] > a[i]){
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        
    }

    void sift_down(int i){
        int l = left(i);
        int r = right(i);
        int minChild = left(i);
        if (l > size){
            return;
        }
        if (r <= size){
            if (a[r] < a[l]) minChild = r;
        }
        if (a[i] > a[minChild]){
            swap(a[i], a[minChild]);
            sift_down(minChild);
        }


    }

    void print(){
        long long sum = 0;
        for(int i = 1; i <= size; i++){
            sum += a[i];
        }
        cout << sum << endl;
    }

};

int main() {
    Heap heap;
    int n;
    cin >> n >> k;
    for (int i = 0; i < n; i ++){
        string s;
        cin >> s;
        if (s == "insert"){
            long long x;
            cin >> x;
            heap.insert(x);

        }
        if (s == "print"){
            if (heap.sz() == 0){
                cout << 0 << endl;
            }
            else {
                heap.print();
            }
        }
    }
    
}
