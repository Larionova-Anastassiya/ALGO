#include <bits/stdc++.h>
using namespace std;

int main() {
    //Ввод
    int n, m;
    cin >> n >> m; //number of blocks and mistakes 

    //вводить номера
    vector<int> vec(n);
    for(int i = 0 ; i < n; i++) {
        cin >> vec[i]; //вводить данные наши числа
        if(i){
            vec[i] += vec[i-1];
        }
    }


    //вводить вторые данные ошибки
    while(m--) {
        int mistakeNum;
        cin >> mistakeNum;


        //Бинарный поиск по префикс сумме
        int left = -1, right = n-1;
        while(left + 1 < right) {
            int midl = (left + right)/2;
            if(vec[midl] >= mistakeNum)
                right = midl;
            else
                left = midl;
        }
        cout << right+1 << endl;
    }

    return 0;
}