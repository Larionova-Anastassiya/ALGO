#include <bits/stdc++.h>
using namespace std;

typedef long long ll; //переименовали для упрощения 



//constants for working and answers
ll MAX_constant = 1e9;
map <int, int> map_global;
int answer_plagiat = 0;





ll Hash(string & s1) { //в которой хранятся указатели на элементы исходного массива данных.
    ll hash1_for_hash = 0; //первый ответ для данных
    ll cur = 1; //для пробега между элементами

    for (int i = 0; i < s1.size(); i++) {

        //специфические данные для хэша для алфавита
        ll curHash = (s1[i] - 'a' + 1) * cur % MAX_constant;
        hash1_for_hash = (hash1_for_hash + curHash) % MAX_constant;
        cur = (cur * 31) % MAX_constant;

    }

    return hash1_for_hash; //вернет наш указатель хэша
}




vector<ll> PrefixAns(string & s1) { //для поиска подстроки в строке

    vector<ll> hashs_ans(s1.size()); //где будут храниться все хэши


    ll cur2 = 1; //для пробега между элементами


    for (int i = 0; i < s1.size(); i++) {

        //добовляем элементы в наш вектор

        hashs_ans[i] = (s1[i] - 'a' + 1) * cur2 % MAX_constant;


        if (i != 0) {
            hashs_ans[i] = (hashs_ans[i] + hashs_ans[i - 1]) % MAX_constant;
        }


        cur2 = (cur2 * 31) % MAX_constant;
    }
    return hashs_ans;
}




void rabinKarp(string & s1, string & s2) { //проверка для ответа на наличие элементов в строках

    if (s2.size() > s1.size()) // если вторая строка больше (кусок для поиска) то не выполняем, это не верно
        return;


    ll hash2_string2 = Hash(s2); //указатели
    vector<ll> hashs_ans = PrefixAns(s1); //проводит поиск элементов


    //пробег по элементам для выполнения работы сравнения
    for (int i = 0; i < s1.size() - s2.size() + 1; i++) {


        ll prefix_string1_ans = hashs_ans[i + s2.size() - 1];


        //условия при проверке индексов и элементов
        if (i != 0) 
            prefix_string1_ans -= hashs_ans[i - 1];

        if (prefix_string1_ans < 0) 
            prefix_string1_ans += MAX_constant;

        if (i != 0) 
            hash2_string2 = (hash2_string2 * 31) % MAX_constant;


        //проверка на одинаковые моменты
        if (hash2_string2 == prefix_string1_ans){

            //если у нас совпадают элементы то мы добавим как причина плагиата
            if (map_global.find(i) != map_global.end()) {
                answer_plagiat++;
            }

            map_global[i] = 1;
        }
    }

}



/*
Проверка на плагиат 

Input
kbtuutbkkbtu
utbkkbtukbtu
kbtu

Output
1
*/
int main() {
    string s1, s2, prefix;
    cin >> s1 >> s2 >> prefix;

    rabinKarp(s1, prefix);  //поиск в первой и подсчет
    rabinKarp(s2, prefix); // поиск во второй и подсчет

    cout << answer_plagiat << endl; //выведет сколько одинаковых моментов
}