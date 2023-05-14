#include <iostream> 
using namespace std; 
 
//поиск по одной стороне (target > arr[midl])
int binary_search_inc(int arr[], int target, int n) { 
    int left = 0, right = n - 1; 
    while (left <= right) { 
        int midl = left + (right - left) / 2; 
        if (target < arr[midl]) { 
            right = midl - 1; 
        } else if (target > arr[midl]) { 
            left = midl + 1; 
        } else { 
        return midl; 
        } 
    } 
    return -1; 
} 
 
//поиск по другой стороне (target < arr[midl])
int binary_search_dec(int arr[], int target, int n) { 
    int left = 0, right = n - 1; 
    while (left <= right) { 
        int midl = left + (right - left) / 2; 
        if (target > arr[midl]) { 
            right = midl - 1; 
        } else if (target < arr[midl]) { 
            left = midl + 1; 
        } else { 
            return midl; 
        } 
    } 
    return -1; 
} 
 

//главный код
int main() { 
    int n, a, b, answer; 
    //Input
    //Example: 5
    //10 15 13 8 23
    cin >> n; 
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
    } 

    /*
    3 4
    25 23 20 19
    13 15 17 18
    12 10 9 8
    */
    cin >> a >> b;  // 3 4
    int arr2d[a][b]; 
    for (int i = 0; i < a; i++) { 
        for (int j = 0; j < b; j++) { 
            cin >> arr2d[i][j]; 
        } 
    } 


    //Process пробегает по всем элементам
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < a; j++) { 
            if (j % 2 == 0) {  //если четное то пробегает по другому пути
                answer = binary_search_dec(arr2d[j], arr[i], b); 
            } else {  //иначе по первому пути
                answer = binary_search_inc(arr2d[j], arr[i], b); 
            } 

            //Вывод ответа
            if (answer != -1) {  //если не ошибка (-1) то координаты
                cout << j << " " << answer << endl; 
                break; 
            } 
            else if (answer == -1 && j == a - 1) { //иначе -1
                cout << -1 << endl; 
                break; 
            } 
        } 
    } 
    return 0; 
}