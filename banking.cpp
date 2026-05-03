#include <iostream>
#include <string>
#include <cmath>
#include <thread>
#include <chrono>

using namespace std;
void Paswword(){
cout << "please enter your password\n";
};
void Donating(int *p){
cout << "would you like to donate blood\n?";
string User_input;
getline(cin >> ws, User_input);
if(User_input == "yes"){
    cout << "thank you so much for you kindness\n";
    cout << "please wait a 30 minute before you start moving\n";
    *p = 1;
    int total_seconds = 30 * 60; 

for(int i = total_seconds; i > 0; i--){
    int minutes = i / 60;
    int seconds = i % 60;

    cout << "Time remaining: " 
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds
         << "   \r";
    cout.flush();
    this_thread::sleep_for(chrono::seconds(1));
}
cout << "Time is up! You are good to go.     \n";
};

};
void checking(){
cout << "Please tell me your weight and height";
    
};
int main(){
    int Donated_blood = 0; int *p;
    p = &Donated_blood;
    while(true){
    cout << "Welcome to the bank" << '\n';
    cout << "1. Enter your account" <<'\n';
    cout << "2. Donating blood" << '\n';
    cout << "3. Checking Health" << '\n';
    cout << "4. exist" << '\n';
    int Answer;
    cin >> Answer;

    switch(Answer){
        case 1: Paswword();
        break;
        case 2: Donating(p);
        break;
        case 3: checking();
        break;
        case 4: 
        if (Donated_blood >= 1){
        cout << "Thank you for droppping by";}else{
            cout << "why would you even come if you don't plan to donate?\n";
        }
    

        system("pause");
        return 0;

    }

}
}