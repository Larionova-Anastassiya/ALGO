#include <iostream> 
using namespace std; 

//Выведите одно число - минимально возможное максимальное количество упырей
int main() { 
    //Input 
    int n, k; 
    cin >> n >> k; 
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 

    //Process
    long long left = 0, right = 1e15, midl, cnt, sum;  //long long чтобы навсякий не выйти за границы int.
    while (left <= right) { 
        //Binary search
        midl = left + (right - left) / 2; 
        cnt = 1; 
        sum = 0; 
        for (int i = 0; i < n; i++) { 
            if (midl < sum + arr[i]) { 
                sum = 0; 
                cnt++; 
            } 
            if (midl < arr[i]) { 
                cnt = k + 1; 
            } 
            sum += arr[i]; 
        } 

        //сдвиги
        if (k < cnt) { 
            left = midl + 1; 
        } else { 
            right = midl - 1; 
        } 
    } 
    
    cout << left; //Output
    
    return 0; 
}