#include <bits/stdc++.h>
using namespace std;

//наименьшую возможную вместимость мешка
long long getTime(vector<long long> &islands, long long bucSize) {
    long long time = 0;
    for(auto i : islands) { // (auto i : islands) = (int i = 0; i < islands.size(); i ++)
        time += i/bucSize;
        if(i%bucSize)
            time++;
    }
    return time;
}

//Основной код
int main() {
    //вводим данные
    long long n, m;
    cin >> n >> m;
    vector<long long> islands(n);
    for(long long &island: islands)
        cin >> island;


    long long left = 0, right = 1e18+123;

    //бин поиск
    while(left + 1 < right) {
        long long midl = (left+right)/2;
        long long timeToSanta = getTime(islands, midl);
        if(timeToSanta <= m)
            right = midl;
        else
            left = midl;
    }
    cout << right;


    return 0;
}