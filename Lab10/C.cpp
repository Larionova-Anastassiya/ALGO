#include <bits/stdc++.h>
using namespace std;


/*
Print one integer m the minimum number of operations. In the second line print m integers, number after every operation.


Input
4 8

Output
1
8 


Input
4 4

Output
0
*/



int main() {
    /*
    CAN

    Multiply number by 2.

    Decrease the number by 1.

    */


    //VALUES
    int num1, num2;
    vector <int> visit;
    queue <int> checking;
    stack <int> answer;
    



    cin >> num1 >> num2; //4 8

    visit.resize(2 * max(num1, num2) + 1, -1);



    //DEfoult first values for vector and queue
    visit[num1] = 0;
    checking.push(num1);
    answer.push(num2);




    //Operations for answers
    while(!checking.empty()) {

        int size = checking.front();
        checking.pop();


        if (size == num2) { //if we have answers
            break;
        }


        //Conditions
        if (size < num2) {
            if(visit[2 * size] == -1 || visit[2 * size] > visit[size] + 1) {
                visit[2 * size] = visit[size] + 1;
                checking.push(2 * size);
            }
        }


        if (size !=0 && (visit[size - 1] == -1 || visit[size - 1] > visit[size] + 1)) {
            visit[size - 1] = visit[size] + 1;
            checking.push(size - 1);
        }
    }
    


    //Cheking answers 

    while (answer.top() != num1) {
        if(visit[answer.top() + 1] + 1 == visit[answer.top()]) {
            answer.push(answer.top() + 1);
        }

        else if(answer.top() % 2 == 0) {
            answer.push(answer.top() / 2);
        }
    }




    if (answer.size() == 0) { //if no values
        cout << 0;
        return 0;
    }

    answer.pop();

    cout << answer.size() << endl; //counting operations


    while(!answer.empty()){ //if we have 1 or 2 values
        cout << answer.top() << ' ';
        answer.pop();
    }

    return 0;
}