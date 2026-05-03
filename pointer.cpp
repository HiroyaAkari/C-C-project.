#include <iostream>
using namespace std;
int main(){
string name = "bro";
int age = 21;
string freepizza[5] = {"pizza1","pizza2","pizza3","pizza4","pizza5" };
string *pName = &name;
int *pAge = &age;
string *pfreepizza = freepizza;

cout << *pName << "\n";
cout << *pAge << '\n';
cout << *pfreepizza << '\n';

return 0;
}