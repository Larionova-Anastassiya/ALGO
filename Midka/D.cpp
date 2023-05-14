#include<bits/stdc++.h>
using namespace std;

//functions

bool prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}


/*
void prime(int n){

    int ans = 0;

    int two = 0;

    while(n % 2 == 0 && two == 0) {
        ans++;
        n = n / 2;
        two++;
        
    }

    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            ans++;
            n = n / i;
        }
    }

    if (n > 2) 
        ans++;

    
    cout << ans;
}
*/

int main(){
    int n; 
    cin >> n;
    

    int ans = 0;
    



    for(int i = 2; i * i <= n; i++){

        int p = i * i;

        if(n % i == 0){

            int m = n / i;

            if(prime(i)){ //проверка если оно простое
                ans++;
            }

            if(n % m == 0 and p != n){
                if(prime(n / i)){
                    ans++;
                }
            }

        }


    }

    
    cout << ans; 
    
    return 0;
}