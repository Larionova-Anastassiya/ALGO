#include <bits/stdc++.h>

using namespace std;
/*
перетасовать массив, чтобы получить идеально 
сбалансированное бинарное дерево поиска 
(например, по британскому летнему времени с префектом бинарное дерево под) 
после добавления элементов (слева направо, опять же).*/
void show(vector<int> &v, int left, int right) {
    int midl = (left+right)/2;
    cout << v[midl] << " ";
    
    if(left == right)
        return;
    //пробег по всем элементам    
    show(v, left, midl-1);
    show(v, midl+1, right);
}

int main() {

    int n;
    cin >> n; //сколько чисел

    int sz = pow(2, n) - 1;
    vector<int> v(sz); //по размеру вектор

    for(int &i : v)
        cin >> i; //вводим данные в вектор
    sort(v.begin(), v.end()); //сортируем
    show(v, 0, sz-1); //показываем результат

    return 0;
}
