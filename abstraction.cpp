#include <iostream>

class stove{
    private: 
    int tempurature = 0;
    public:

    int gettempurature(){
        return tempurature;
    }
    void settempurature(int tempurature){
        if(tempurature < 0){
            this->tempurature = 0;
}else if(tempurature >= 10){
    this->tempurature = 10;
}
        this->tempurature = tempurature;
    }

};
int main(){
    stove stove;
    stove.settempurature(5);

    std::cout <<"the tempurature setting is: " << stove.settempurature(5);

    system("pause");
    return 0;
}