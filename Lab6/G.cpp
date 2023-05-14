#include <bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cin >> size;

    map<string, string> name; //all string names

    map<string, string>::iterator iterator; 


    for(int i = 0; i < size; i++) {

        string old_nicknames, new_nicknames;
        cin >> old_nicknames >> new_nicknames; //Aslan Nurbol / Nurbol HackMachine


        name[old_nicknames] = new_nicknames;

    //use iterator we can for use for map
        for(iterator = name.begin(); iterator != name.end(); iterator++){

            if(iterator->second == old_nicknames){
                iterator->second = new_nicknames; //changes

                name.erase(old_nicknames); //delete this
            }
        }
    }


    cout << name.size() << endl; //new size for names


    //output new nicknames
    for(iterator = name.begin(); iterator != name.end(); iterator++){
        cout << iterator->first << " " << iterator->second << endl;
    }

    return 0;
}
