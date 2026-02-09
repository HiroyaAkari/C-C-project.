#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    char name[10];
    int dic, Bin=0, i=0;

    start: 

    printf("please input the number you want to find: ");
    scanf("%d", &dic);
    while(dic>0){
        Bin = Bin + (dic%2)*pow(10,i);
        i++;
        dic = dic/2;
    }
    printf("%000000d\n", Bin);

    printf("would you like to continues?");
    scanf("%s", &name);

    if(name == "yes" && "Yes"){goto start;
    } else{
        printf("good bye"); }

    return 0;
}