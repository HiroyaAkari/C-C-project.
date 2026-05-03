#include <iostream>
#include <string>
using namespace std;
int main(){
    cout << "what is your name :";
    string Name;
    getline(cin >> ws, Name);
    cout <<"how old are you : ";
    int age;
    cin >> age;

    if(age>=18){
        cout << "welcome to our game " << Name << "\n";
        cout << "you're " << age << "year old that why we let you in";
    }else if (age > 100){
        cout << "you're too old sir";
    }else {
        cout << "you're too young kid";
    }
    system("pause");
    return 0;
}