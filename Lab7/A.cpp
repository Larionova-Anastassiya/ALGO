#include <iostream>
#include <vector>
using namespace std;


vector<vector<string> > vec(100000); //defolt


void merge(int n, int l, int middle, int r) {
    int size, index, cnt;

    size = l;
    index = middle + 1;
    cnt = l;

    string str2[r + 1];


    while(size <= middle && index <= r) {

        if(vec[n][size].size() < vec[n][index].size()) {
            str2[cnt] = vec[n][size];
            size++;
            cnt++;
        }

        else if(vec[n][size].size() > vec[n][index].size()) {
            str2[cnt] = vec[n][index];
            index++;
            cnt++;
        }

        else {
            str2[cnt] = vec[n][size];
            size++;
            cnt++;
        }
    }


    // for but dont use "int i = .." because we have values;
    for(; size <= middle; size++) {
        str2[cnt] = vec[n][size];
        cnt++;
    }
    for(; index <= r; index++) {
        str2[cnt] = vec[n][index];
        cnt++;
    }
    for(size = l; size <= r; size++) {
        vec[n][size] = str2[size];
    }
}


//sorting use all
void mergeSort(int n, int l, int r){

    if(l < r){

        int middle = (l + r) / 2;
        mergeSort(n, l, middle);
        mergeSort(n, middle + 1, r);

        //all sorting
        merge(n, l, middle, r);

    }
}





//in main use this solving
void solve_string(int size){
    string string_input;


    getline(cin >> ws, string_input); //input strings


    string_input += " "; 
    string empty_ans = "";


    for(int index = 0; index < string_input.size(); index++){

        if(string_input[index] == ' '){
            vec[size].push_back(empty_ans);
            empty_ans = "";
        }

        else{
            empty_ans += string_input[index]; //values
        }
    }


    mergeSort(size,0, vec[size].size() - 1); //all string sorting

    //output answers
    for(int index = 0; index < vec[size].size(); index++){
        cout << vec[size][index] << " ";
    }


    cout << endl;
}






int main(){
    int n;
    cin >> n;

    for(int size = 0; size < n; size++){
        solve_string(size); //solving for all values all strings
    }
}