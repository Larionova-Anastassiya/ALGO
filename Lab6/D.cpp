#include<bits/stdc++.h>
using namespace std;



int ans_val(string s){
    int ans = 0;

    if(s[0] == '0'){
        return int(s[1]) - 48;
    }

    for (int i = 0; i < s.size(); i++) {
        ans += pow(10, s.size() - i - 1) * (int(s[i]) - 48); //use specific formul for answers use parameters
    }
    return ans;
}


//create Date and use values
struct Date{
    //values in date
    int year;
    int month;
    int day;


    Date(string format) { //specific format string - 01-12-2000
        bool d = true;
        string string_date = ""; //string for use values

        for (int i = 0; i < format.size(); i++) {

            if(format[i] == '-'){

                if(d){ //first we can see day
                    day = ans_val(string_date);
                    string_date = "";
                    d = false;
                }

                else{ //next see month and save this
                    month = ans_val(string_date);
                    string_date = "";
                }

                continue;
            }

            string_date += format[i]; //push values
        }

        year = ans_val(string_date); //year see and use
    }


    //print answers in main
    void print(){

        //with condition
        if(day < 10){ //if only 1 values day (1.12.2022)

            if(month < 10){ //if only 1 values day and month (1.2.2022)
                cout << '0' << day << '-' << '0' << month << '-' << year << endl;
                return;
            }

            cout << '0' << day << '-' << month << '-' << year << endl;
            return;
        }


        if(month < 10){ //if only 1 values month (10.2.2022)
            cout << day << '-' << '0' << month << '-' << year << endl;
            return;
        }

        //all values if > 10 (11.12.2022)
        cout << day << '-' << month << '-' << year << endl;

    }
};




//bool check for sort
bool cmp(Date * d1, Date * d2){
    if(d1->year < d2->year) //check years
        return true;


    if(d1->year == d2->year) { //if years equal so check month

        if(d1->month < d2->month) 
            return true;

        if(d1->month == d2->month) { //if month equal so check day
            return d1->day < d2->day;
        }

    }
    return false;
}




//Basics function for Heap

void heapify(vector <Date *> &vec, int size, int i){
    int biggest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < size && cmp(vec[biggest], vec[l])){
        biggest = l;
    }

    if(r < size && cmp(vec[biggest], vec[r])){
        biggest = r;
    }

    if(biggest != i){
        swap(vec[i], vec[biggest]);
        heapify(vec, size, biggest);
    }
}


//Basic sort for heap bun use vector
void heapSort(vector<Date *> &vec){
    for (int i = (vec.size() - 1) / 2; i >= 0; i--) {
        heapify(vec, vec.size(), i);
    }

    for (int i = vec.size() - 1; i >= 0; i--) {

        swap(vec[0], vec[i]);
        heapify(vec, i, 0);

    }
}



int main(){
    int n;
    cin >> n; //size
    string s;

    vector<Date *> date; //create vector

    //INput
    for (int i = 0; i < n; i++) {
        cin >> s; //new date 01-12-2000 ...

        Date * newDate = new Date(s);
        date.push_back(newDate);

    }


    heapSort(date);

    //Output answer
    for (int i = 0; i < n; i++){
        date[i]->print();
    }
    
    return 0;
}