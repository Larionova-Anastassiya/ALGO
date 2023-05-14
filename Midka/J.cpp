#include <bits/stdc++.h>
using namespace std;


/*
Input
9
6
1 3 4 6 7 9
Output
3 6 
// оценки по двум задачам, выбранным в порядке возрастания.
*/
int main(){
    int score, num;
    cin >> score; //score must
    cin >> num; //number of problems
    int arr[num]; //arrays for answer

    for(int i = 0; i < num; i++){
        cin >> arr[i]; //push new values
    }

    sort(arr, arr + num); //sort in algorithm for all arrays


    for(int i = 0; i < num; i++){

        //example linked sorting for two space-separated integers - the scores of two problems chosen in ascending order.
        int difference = score - arr[i];
        int l = 0, r = num-1;


        while(l <= r) {

            int middle = l + (r - l) / 2;


            if(arr[middle] == difference && middle != i) { //conditions for answers
                cout << min(arr[i], difference) << ' ' << max(arr[i], difference); //two space-separated integers
                return 0;
            }

            else if(arr[middle] > difference) {
                r = middle - 1;
            }

            else {
                l = middle + 1;
            }
        }
    }
}