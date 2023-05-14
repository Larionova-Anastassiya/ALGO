#include <iostream>
using namespace std;
/*
Input
4
1 3 3000 3002
Output
1 2 3 3


For 1st ping at ti = 1, you did that ping [1]
For 2nd ping at ti = 3, last two pings are [1, 3]
For 3rd ping at ti = 3000, there were 3 pings [1, 3, 3000]
For the last ping at ti = 3002, there were 3 pings in the last 3000 milliseconds [3, 3000, 3002]
*/

int main(){
    int n;
    cin >> n; // сколько в массиве будет : 4

    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i]; //вводим массив : 1 3 3000 3002
    }
    
    int val = 0; //пробегаться по элементам массива
    int ping = 1; //счетчик пингов

    
    cout << 1 << ' '; // для 1 первого элемента


    for(int i = 1; i < n; i++){
        ping++; //он увеличится в любом случае при действии

        if(a[i] - a[val] > 3000){ //проверка чтобы разница была больше 3000

            while(a[i] - a[val] > 3000){ //выполняется пока больше
                val++; //значение увеличится и пойдет дальше
                ping--;  //уменьшится если больше 3000
            }

        }



        cout << ping << ' '; //выведет ответ наших пингов
    }
}