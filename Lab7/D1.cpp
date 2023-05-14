#include <bits/stdc++.h>
using namespace std;

double GPA_values(string grade) {
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



//check for sorting with pair return high element
int high_element(pair<pair<string, string>, double> pair1, pair<pair<string, string>, double> pair2) {

    //check conditions

    if (pair1.second > pair2.second) {
        return 1;
    }


    else if (pair1.second < pair2.second) {
        return 2;
    }


    else { //if equal so next cheking
        if (pair1.first.first > pair2.first.first) {
            return 1;
        }

        else if (pair1.first.first < pair2.first.first) {
            return 2;
        }

        else { //if equal so next cheking
            if (pair1.first.second >= pair2.first.second) {
                return 1;
            }

            return 2;
        }
    }
}


//basic merge sorting with vector
void merge(vector<pair<pair<string, string>, double> > &vec, int l, int middle, int r) { //create merge and all sort

    int size1 = middle - l + 1;
    int size2 = r - middle;

    vector<pair<pair<string, string>, double> > vec1, vec2;

    for (int i = 0; i < size1; i++) {
        vec1.push_back(vec[l + i]);
    }

    for (int i = 0; i < size2; i++) {
        vec2.push_back(vec[middle + 1 + i]);
    }

    int i = 0, j = 0, cnt = l; //new values for while all elements

    while (i < size1 && j < size2) {

        if (high_element(vec1[i], vec2[j]) == 1) {
            vec[cnt] = vec2[j];
            j++;
        }

        else {
            vec[cnt] = vec1[i];
            i++;
        }
        cnt++;
    }  

    while (i < size1) {
        vec[cnt] = vec1[i];
        i++;
        cnt++;
    }

    while (j < size2) {
        vec[cnt] = vec2[j];
        j++;
        cnt++;
    }
}

void mergeSort(vector<pair<pair<string, string>, double> > &vec, int l, int r) {
    
    if (l < r) {

        int middle = l + (r - l) / 2;
        mergeSort(vec, l, middle);
        mergeSort(vec, middle+1, r);

        //all sort
        merge(vec, l, middle, r);
    }
}






int main(){
    int n, k, count;
    cin >> n; //size



    vector<pair<pair<string, string>, double> > vec;
    string surname, name, grade;

    //cout << fixed << showpoint;
    //cout << setprecision(3);


    for(int i = 0; i < n; i++){
        
        cin >> surname >> name >> k; //Issenbayev Yernur 4

        int cnt = 0;
        double sums = 0;
        

        for(int j = 0; j < k; j++){
        

            cin >> grade >> count; //grades A 4 D+ 2 B 3 A+ 4

            sums += GPA_values(grade) * count; //solve use gpa
            cnt += count;
        }

        vec.push_back(make_pair(make_pair(surname, name), sums / cnt));
    }
    mergeSort(vec, 0, n-1); //sorting all

    cout << fixed << setprecision(3);

    //output answers
    for(int i = 0; i < n; i++){
        cout << (vec[i]).first.first << ' ' << (vec[i]).first.second << ' ' << (vec[i]).second << endl;
    }
}