#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct answer_deq{
    vector <int> vec; //create vector


    //functions
    void add_val(int condition) {
        vec.push_back(condition);
    }


    void delete_val() {
        vec.pop_back();
    }


    void getCur() {

        if(vec.size()) 
            cout << vec[vec.size() - 1] << endl; //print value

        else 
            cout << "error" << endl; //if not value in vector
    }


    void getMax(){
        long long maximum = -1e9;

        if(vec.size()) {
             
            for(int i = 0; i < vec.size(); ++i) {

                if(vec[i] > maximum) {
                    maximum = vec[i];
                }

            }

            cout << maximum << endl;

        }
        
        else 
            cout << "error" << endl; //if not value in vector
    }

};



int main(){
    answer_deq answer;

    int n; //size

    cin >> n;


    for(int i = 0; i < n; i++){
        string condition; //for word
        cin >> condition;

        if(condition == "add") {
            int val;
            cin >> val;

            answer.add_val(val);
        }

        else if(condition == "delete") {
            answer.delete_val();
        }

        else if(condition == "getcur") {
            answer.getCur();
        }

        else if(condition == "getmax") {
            answer.getMax();
        }
    }
}