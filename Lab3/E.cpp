#include <bits/stdc++.h>
using namespace std;

struct place{
    int x1, x2;
    int y1, y2;
};

//выполняет наше условие для результата 
int getsheepsCount(vector<place> &sheeps, int x) {
    int res = 0;
    for(auto &sheep : sheeps) {
        if(sheep.x1 <= x && sheep.y1 <= x && sheep.x2 <= x && sheep.y2 <= x)
            res++;
    }
    return res;
}


int main() {
    //вводим данные
    int n, k;
    cin >> n >> k;

    vector<place> sheeps(n);
    for(auto & sheep : sheeps) {
        cin >> sheep.x1 >> sheep.y1 >> sheep.x2 >> sheep.y2;
    }


    //бинарный поиск
    int left = 0, right = 1e9+2;

    while(left + 1 < right) {
        int midl = (left+right)/2;
        if(getsheepsCount(sheeps, midl) >= k)
            right = midl;
        else
            left = midl;
    }

    cout << right;

    return 0;
}
