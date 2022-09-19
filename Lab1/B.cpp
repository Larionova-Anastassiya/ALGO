#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n; //вводим сколько всего чисел будет

    stack<int> st;
    vector<int> vec;

    for (int i = 0; i < n; i++){ //вводим числа пока не дойдем до н и добавляем в вектор (модель массива)
        int a;
        cin >> a;
        vec.push_back(a); //добавляем в массив
    }

    //выполняем условия задачи показать если рядом есть меньше и какое число, иначе -1
    for (int i = 0; i < vec.size(); i++){

        if(!st.empty()){
            while(!st.empty() && st.top() > vec[i]){ //если есть больше и не пустой то добавим
                st.pop();
            }
        }

        if(st.empty()){ //если ничего не добавил то -1 и нет подходящего
            cout<< "-1";
        }

        else{
            cout<< st.top();
        }
        cout<<" "; //вывод через пробел
        st.push(vec[i]);
    }
}
