#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){

    start:

    int N, S;
    printf("please put the number you want to convert N: ");
    scanf("%d", &N);

     S = 0;
    while (N>0){
        S = S*10 + (N%10);
        N = N/10;
    }
    char Answer[10];
    printf("%d", S);
    printf("\n would you like to continues?");
    scanf("%s", &Answer);

    if (Answer == "yes"  && "Yes" && 'Y' && 'y'){goto start;}
    else {
        printf("good bye");
    }


    return 0;
}