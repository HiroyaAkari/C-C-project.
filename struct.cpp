#include <iostream>
#include <string>

struct student{
    std::string name; 
    double gpa;
    bool enrolled;
};

int main(){
    student student1;
    student1.name = "Ly minh";
    student1.gpa = 3.2;
    student1.enrolled = true;

    std::cout << student1.name << "\n";
    std::cout << student1.gpa << "\n";
    std::cout <<student1.enrolled << "\n";

    return 0;
}
