#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue <int> bor, nur; //два для данных где карты
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        bor.push(n); //добавляем 5 карт борису
    }
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        nur.push(n); //добавляем 5 карт нурсику
    }


    int cnt = 0; //подсчет

    //цикл карт когда если больше, то забирает две карты себе проигрыш если кончились
    while(!bor.empty() && !nur.empty()) {

        if (cnt > 1000000) {//если много махинация выполнено то ничья
            cout << "blin nichya";
            return 0;
        }


        if (bor.front() == 0 and nur.front() == 9) {
            bor.push(bor.front());
            bor.push(nur.front());
            bor.pop();
            nur.pop();
        }
        else if (bor.front() == 9 and nur.front() == 0) {
            nur.push(bor.front());
            nur.push(nur.front());
            bor.pop();
            nur.pop();
        }


        else if (bor.front() > nur.front()) { //если у числа бориса больше то ему прибавка а нурику убрать
            bor.push(bor.front());
            bor.push(nur.front());
            bor.pop();
            nur.pop();
        }
        else if (bor.front() < nur.front()){ //если у бориса меньше то нурику отдаются и у бориса забирается
            nur.push(bor.front());
            nur.push(nur.front());
            bor.pop();
            nur.pop();
        }
        cnt++; //идет подсчет цикла карт добавления и убавления
    }


    if(bor.empty()) //если у бориса пусто то выиграл нурик
        cout << "Nursik " << cnt;
    else
        cout << "Boris " << cnt;
}