#include <iostream>
#include <vector>

using namespace std;



vector<pair<vector<long long int>, long long int> > vec; //for answers


//merge sorting with vector
void mergeSortOne(int left, int middle, int right){
    int index,index2,cnt;


    index = left;
    index2 = middle + 1;
    cnt = left;


    vector<pair<vector<long long int>, long long int> > b(right + 1);


    while(index <= middle && index2 <= right){

        if(vec[index].second > vec[index2].second) {
            b[cnt] = vec[index];
            index++;
            cnt++;
        }


        else if(vec[index].second < vec[index2].second) {
            b[cnt] = vec[index2];
            index2++;
            cnt++;
        }


        else if(vec[index].second == vec[index2].second) { //if equals next checking

            for(int cur = 0; cur < vec[index2].first.size(); cur++) {

                if(vec[index].first[cur] < vec[index2].first[cur]) {
                    b[cnt] = vec[index];
                    cnt++;
                    index++;
                    cur = vec[index2].first.size();
                }


                else if(vec[index].first[cur] > vec[index2].first[cur]) {
                    b[cnt] = vec[index2];
                    cnt++;
                    index2++;
                    cur = vec[index2].first.size();
                }


                else if(cur == vec[index2].first.size() - 1) {
                    b[cnt] = vec[index];
                    cnt++;
                    index++;
                    cur = vec[index2].first.size();
                }
            }
        }
    }



    for(; index <= middle; index++) {
        b[cnt] = vec[index];
        cnt++;
    }


    for(; index2 <= right; index2++) {
        b[cnt] = vec[index2];
        cnt++;
    }


    // for but dont use "int index = .." because we have index = left;
    for(index = left; index <= right; index++) {
        vec[index] = b[index];
    }


}



//basics merge sort
void mergeSort(int left, int right){

    if(left < right){

        int middle = (left + right) / 2;
        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        mergeSortOne(left, middle, right);

    }
}

//Print rows in desired sorted order.
/*
Input
5 3
1 2 3
1 2 4
1 3 2
6 0 0
2 3 2
Output
1 2 4 
2 3 2 
1 2 3 
1 3 2 
6 0 0 
*/


int main(){
    int n,m;
    cin >> n >> m; //sizes rows and columns


    for(int index = 0; index < n; index++){
        long long int sum = 0; //for all strings new sum 


        vector<long long int> a;


        for(int index2 = 0; index2 < m; index2++){

            long long int val;
            cin >> val; //values

            a.push_back(val);

            sum += val; //sum all values in string

        }

        vec.push_back(make_pair(a,sum)); //pair for sorting
    }


    mergeSort(0, n - 1);


    //output answer
    for(int index = 0; index < n; index++){

        for(int index2 = 0; index2 < m; index2++){

            cout << vec[index].first[index2] << " ";
        }


        cout << endl;
    }
}