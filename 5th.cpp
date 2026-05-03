#include <iostream>
using namespace std;
int searchArray(string array[], int size, string element);
int main(){
    string food[] = { "pizza", "hamburger", "hotdog"};
    int size = sizeof(food)/sizeof(food[0]);
    int index;
    string myfood;

    cout <<"enter element to search for: " << '\n';
    getline(cin >> ws , myfood);

    index = searchArray(food, size, myfood);

    if(index != -1){
        cout << myfood << " is at index " << index;
    }
    else{
        cout << myfood << "is not in the array";
    }
    
    return 0;
}
int searchArray(string array[], int size, string element){

    for(int i = 0; i < size; i++){
        if(array[i] == element){
            return i;
        }
    }return -1;
}