#include <bits/stdc++.h>
using namespace std;

//найти последнее число которое меньше или равно нашему
int getLastCompetitor(vector<int> &competitors, int power) {
    if(power < competitors[0])
        return -1;

    int left = 0, right = competitors.size();

    while(left + 1 < right) {
        int midl = (left+right)/2;
        if(competitors[midl] <= power)
            left = midl;
        else
            right = midl;
    }
    return left;
}


int main() {
    //вводим данные 
    int n;
    cin >> n;
    vector<int> comp(n);
    vector<int> Sum(n);

    for(int &i : comp){  //по элементам пробегается добавляя
        cin >> i; 
    }

    sort(comp.begin(), comp.end()); //отсортируем


    Sum[0] = comp[0];
    for(int i = 1; i < n; i++)
        Sum[i] = comp[i] + Sum[i-1];


    int tests;
    cin >> tests; //сколько проверок сделать
    while (tests--) {
        int power;
        cin >> power;
        int id = getLastCompetitor(comp, power);
        cout << (id != -1? id+1: 0) << ' ' << (id != -1 ? Sum[id]: 0) << endl;  // id != -1 пока не равно ошибке -1 то будет проверять
    }

    return 0;
}


