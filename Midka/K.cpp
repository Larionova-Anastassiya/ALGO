#include <bits/stdc++.h>
using namespace std;
 

void print(deque<int>& Deque) {
    while (!Deque.empty()) {
        cout << Deque.front() << " ";
        Deque.pop_front();
    }
}
 

void reverse(deque<int>& Deque) {
    stack<int> Stack;
    while (!Deque.empty()) {
        Stack.push(Deque.front());
        Deque.pop_front();
    }
    while (!Stack.empty()) {
        Deque.push_front(Stack.top());
        Stack.pop();
    }
}
 

int main() {
    
    int n;
    cin >> n;
    
    deque<int> deque;
    
    
    while(n--){
        
        int v;
        int m;
        cin >> v;
        
        if(v == 1){
            cin >> m;
            deque.push_front(m);
        }
        
        if(v == 2){
            reverse(deque);
        }
    }
    print(deque);
   
}