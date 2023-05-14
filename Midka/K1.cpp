#include <iostream>
using namespace std;


//global values for reverse
int a[600000];
int first_in_left = 299999, second_in_right = 300000;



int main(){

    int size_operation;
    cin >> size_operation;




    int values_for_reverse = 0; // 0 for ascending, 1 for descending

    for(int i = 0; i < size_operation; i++){

        int operation;
        cin >> operation; //num operations 1 or 2



        if(operation == 1){ //input value in massiv

            int value;
            cin >> value;


            if(values_for_reverse == 0){ //ascending
                a[second_in_right] = value;
                second_in_right++;
            }


            else if(values_for_reverse == 1){ //descending
                a[first_in_left] = value;
                first_in_left--;
            }
        }


        else if(operation == 2){ //reverse all

            if(values_for_reverse == 0){ //if ascending
                values_for_reverse = 1;
            }


            else{
                values_for_reverse = 0; // if descending
            }
        }
    }


    //OUTPUT answers:
    if(values_for_reverse == 1){
        for(int i = second_in_right - 1; i > first_in_left; i--){ //down numbers
            cout << a[i] << ' ';
        }
    }


    else{
        for(int i = first_in_left + 1; i < second_in_right; i++){ //up numbers 
            cout << a[i] << ' ';
        }
    }
}

