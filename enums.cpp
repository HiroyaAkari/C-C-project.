#include <iostream>
using namespace std;
enum Day {sunday = 0, monday = 1, tuesday = 2 , wednesday = 3, thursday = 4, friday = 5, saturday = 6 };

int main(){
    Day today = monday;
    switch(today){
        case sunday: 
        case monday: "it's monday bro";
        break;
        case tuesday: 
        case wednesday: 
        case thursday:
        case friday:
        case saturday:
    }
}