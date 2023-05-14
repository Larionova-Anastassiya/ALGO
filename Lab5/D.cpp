#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m, cnt = 0;

class Heap{
    long long a[100005];
    long long size;
public:
    Heap(){
        a[0] = -2147483647;
        size = 0;
//        a[0] = 20000000000;
    }

    int parent(int i){
        return i / 2;
    }

    int left(int i){
        return i * 2;
    }

    int right(int i){
        return i * 2 + 1;
    }


    void insert(long long val){
        size++;
        a[size] = val;
        sift_up(size);
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

    long long extract_min(){
        long long min = a[1];
        swap(a[1], a[size]);
        size--;
        sift_down(1);
        return min;
    }


    void mix(){
        while (a[1] < m && cnt < n){
            cnt++;
            long long j = extract_min();
            long long q = extract_min();
            long long jq = j + 2 * q;
            insert(jq);
        }
        if (cnt >= n){
            cout << -1 << endl;
        }
        else{
            cout << cnt << endl;
        }
    }


    void print(){
        for (int i = 1; i <= size; i ++){
            cout << a[i] << " ";
        }
        cout << endl;
    }


};

int main() {
    Heap heap;
    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        int x; cin >> x;
        heap.insert(x);
    }

    heap.mix();
    return 0;

}
