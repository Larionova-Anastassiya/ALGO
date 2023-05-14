#include <bits/stdc++.h>
using namespace std;

//returns which one is higher
int comp(pair<pair<string, string>, double> p1, pair<pair<string, string>, double> p2){
    if(p1.second > p2.second){
        return 1;
    }
    else if(p1.second < p2.second){
        return 2;
    }
    else{
        if(p1.first.first > p2.first.first){
            return 1;
        }
        else if(p1.first.first < p2.first.first){
            return 2;
        }
        else{
            if(p1.first.second >= p2.first.second){
                return 1;
            }
            return 2;
        }
    }
}


void merge(vector<pair<pair<string, string>, double> > &v, int left, int mid, int right){
    int size1 = mid - left + 1;
    int size2 = right - mid;

    vector<pair<pair<string, string>, double> > v1, v2;

    for(int i = 0; i < size1; i++){
        v1.push_back(v[left + i]);
    }

    for(int i = 0; i < size2; i++){
        v2.push_back(v[mid + 1 + i]);
    }

    int i = 0, j = 0, cnt = left;

    while(i < size1 && j < size2){
        if(comp(v1[i], v2[j]) == 1){
            v[cnt] = v2[j];
            j++;
        }
        else{
            v[cnt] = v1[i];
            i++;
        }
        cnt++;
    }  
    while(i < size1){
        v[cnt] = v1[i];
        i++;
        cnt++;
    }

    while(j < size2){
        v[cnt] = v2[j];
        j++;
        cnt++;
    }
}

void mergeSort(vector<pair<pair<string, string>, double> > &v, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);

        merge(v, left, mid, right);
    }
}


int main(){
    int n;
    cin >> n;

    map <string, double> m;
    m.insert(make_pair("A+", 4.00));
    m.insert(make_pair("A", 3.75));
    m.insert(make_pair("B+", 3.50));
    m.insert(make_pair("B", 3.00));
    m.insert(make_pair("C+", 2.50));
    m.insert(make_pair("C", 2.00));
    m.insert(make_pair("D+", 1.50));
    m.insert(make_pair("D", 1.00));
    m.insert(make_pair("F", 0));

    vector<pair<pair<string, string>, double> > v;
    cout << fixed << showpoint;
    cout << setprecision(3);
    for(int i = 0; i < n; i++){
        string lastname, firstname;
        int t;
        cin >> lastname >> firstname >> t;
        double sum = 0;
        int total_credits = 0;
        for(int j = 0; j < t; j++){
            string mark;
            int credits;
            cin >> mark >> credits;

            sum += m[mark] * credits;
            total_credits += credits;
        }

        v.push_back(make_pair(make_pair(lastname, firstname), sum / total_credits));
    }
    mergeSort(v, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << v[i].first.first << ' ' << v[i].first.second << ' ' << v[i].second << endl;
    }
}