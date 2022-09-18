#include <iostream>
#include<stdlib.h>
using namespace std;
 
bool isPrime(int num){ //проверка на прайм число

    int count = 0;//счетчик 
    for (int j = 2; j < num; j++){ //проверка по всем числам не доходя до нашего
        if (num % j == 0){ //если делится на числа любые 
            count = 1;
            break;
        }
    }
    if (count == 0){ //если не делятся то прайм
        return true;
    }
    else{
        return false;
    }
}
 
int main(){
 
	int n,num=1;
    int count = 0;
    cin>>n; //вводим место числа
    while (true){ //пока правда будет увеличиваться и делать
        num++;
        if(isPrime(num)){ //если прайм то добавит в счетчик
            count++;
        }
        if(count==n){
            cout << num;//вывод числа прайм
            break;
        }
    }
	
}