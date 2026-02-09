#include <stdio.h>
#include <conio.h>
#include <math.h>

void main(){
    int A, B = 0, i = 0;

    printf("input ");
    scanf("%d", &A);

    while (A>0){
        B = B + (A % 10);

        A = A/10;
    }

    printf("%d", B);
    
    getch();
}