#include <iostream>
#include <string>
using namespace std;
void walk(int step);
int main(){

    return 0;
}
void walk(int step){
    if(step > 0){
        cout << "you take a step\n";
        walk(step - 1);

    }
}