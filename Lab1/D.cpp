#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<char> sta;
    string ans;
    cin >> ans;
    for (int i=0; i<ans.size(); i++){
        if (sta.empty()){
            sta.push (ans[i]);
            }
        else{
            if (sta.top()==ans[i]){
                sta.pop();}
            else 
                sta.push(ans[i]);
            }
    }
    if (sta.empty()){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}