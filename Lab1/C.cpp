#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    stack<char> st1,st2;

    char a;
    string s1, s2;
    cin >> s1 >> s2; //abc## a#b#a
    
    //проходит по всем буквам первого слова удаляя значение при встрече знака
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != '#'){
            st1.push(s1[i]);
        }
        else 
            st1.pop();
    }

    //проходит по всем буквам второго слова удаляя значение при встрече знака
    for(int i = 0; i < s2.size(); i++){
        if(s2[i] != '#'){
            st2.push(s2[i]);
        }
        else 
            st2.pop();
    }

    //сравниваем буквы которые ответах остались
    if (st1 == st2)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}