#include <iostream>
using namespace std;
    class student{
        public: 
        string name;
        int age;
        double gpa;

    student (string name, int age, double gpa){
        this -> name = name;
        this -> age = age;
        this -> gpa = gpa;
    }
    };
int main(){
    student student1("boobobi", 34, 4.0);
    student student2("broV", 12, 4.0);

    cout << student1.name << '\n';
    cout << student1.age << '\n';
    cout << student1.gpa << '\n';

    return 0;
}