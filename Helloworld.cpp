#include <iostream> 
#include <string>

int main(){
    std::cout <<"what is your name?";
    std::string Name; 
    std::getline(std::cin>>std::ws, Name);
    std::cout <<"and How old are you?";
    int age;
    std::cin >> age;

    std::cout << "hello so your name is " << Name << "\n";
    std::cout << "you are " << age << "year old" << "\n";

    system("pause");
    return 0; 
}