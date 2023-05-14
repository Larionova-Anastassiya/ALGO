#include <bits/stdc++.h>
using namespace std;

double GPA_values(string grade){
    //values in table specific for grades
    if(grade == "A+")
        return 4.0;
    if(grade == "A")
        return 3.75;
    if(grade == "B+")
        return 3.50;
    if(grade == "B")
        return 3.0;
    if(grade == "C+")
        return 2.50;
    if(grade == "C")
        return 2.0;
    if(grade == "D+")
        return 1.5;
    if(grade == "D")    
        return 1.0;

    return 0;
}


//check for sorting with pair
bool check(pair <pair <string, string>, double> &pair1, pair <pair <string, string>, double>&pair2){
    if(pair1.second < pair2.second)
        return true;

    if(pair1.second == pair2.second) { //if equals continue check

        if(pair1.first.first < pair2.first.first)
            return true;

        if(pair1.first.first == pair2.first.first) { //if equals continue check
            return pair1.first.second < pair2.first.second;
        }

        return false;
    }
    return false;
}




//Basics functions for Heap but use vector pairs
void heapify(vector <pair <pair <string, string>, double> > &vec_heap, int size, int i){
    int biggest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < size && check(vec_heap[biggest], vec_heap[l])) {
        biggest = l;
    }

    if(r < size && check(vec_heap[biggest], vec_heap[r])) {
        biggest = r;
    }

    if(i != biggest) {
        swap(vec_heap[biggest], vec_heap[i]);
        heapify(vec_heap, size, biggest);
    }
}


//sort for heap basic
void heapSort(vector <pair <pair <string, string>, double> > &vec_heap){

    int size = vec_heap.size();

    for(int i = (size - 1) / 2; i >= 0; i--) {
        heapify(vec_heap, size, i);
    }

    for(int i = size - 1; i >= 0; i--) {
        swap(vec_heap[0], vec_heap[i]);
        heapify(vec_heap,  i, 0);
    }
}



/*
5
Issenbayev Yernur 4 A 4 D+ 2 B 3 A+ 4
Yermekbayeva Diana 3 A+ 4 B+ 3 B 1
Kadyrov Asman 2 A+ 4 A+ 4
Stepanenko Ivan 3 C+ 3 F 1 A+ 5
Bissimbayev Arystan 3 A+ 4 A+ 5 D 1
*/

int main(){

    int n, k, count;
    cin >> n; //size

    vector <pair <pair <string, string>, double> > v;
    string name, surname, grade;


    for(int i = 0; i < n; i++) {
        cin >> surname >> name >> k; //Issenbayev Yernur 4

        int cnt = 0;
        double sums = 0;

        for(int j = 0; j < k; j++) {
            cin >> grade >> count; //grades A 4 D+ 2 B 3 A+ 4
            sums += GPA_values(grade) * count; //solve use gpa
            cnt += count;
        }

        v.push_back(make_pair(make_pair(surname, name), sums / cnt));
    }

    heapSort(v); //sorting all

    cout << fixed << setprecision(3);


    //output answers
    for(int i = 0; i < n; i++){
        cout << (v[i]).first.first << ' ' << (v[i]).first.second << ' ' << (v[i]).second << endl;
    }
    return 0;
}