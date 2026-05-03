#include <iostream>
#include <string>
using namespace std;
typedef std::string text;

int main(){
    char grade = 'A';
    bool stuent = false;

    cout <<"What is your name? \n";
    text Name;
    cin >> Name; 
    cout << "your name is " << Name << "\n";
    cout << "alright welcome \n" << Name;
    cout << "what is 4 + 8 \n";

    int Answer;
    cin >> Answer; 

    cout << " if your answer is 12 you're correct \n";
    system("Pause");
    return 0;


}