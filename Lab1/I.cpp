#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){

    string s;
    deque <int> deq1, deq2; //значения будут лидеров двух
    int n;
    cin >> n; //введем число
    cin >> s; // введем строку
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'S'){
            deq1.push_back(i); //если голосуют за сакураги добавит туда
        }
        else {
            deq2.push_back(i);
        }
        }

    //будет повторяться до тех пор пока не останется один решающий отдающий голос
    while (!deq1.empty() && !deq2.empty()){
        int i = deq1.front();
        int j = deq2.front();
    
    if (i < j){
        deq2.pop_front();
        deq1.push_back (i + s.size());
        deq1.pop_front(); 
        }
        
    else if(i > j){
        deq1.pop_front();
        deq2.push_back (j+s.size());
        deq2.pop_front(); 
        }
    }


    if (deq1.empty()){ //вывод выбора после цикла выбора когда они убирают друг друга
        cout << "KATSURAGI";
    }
    else {
        cout << "SAKAYANAGI";
    }
    return 0;
}