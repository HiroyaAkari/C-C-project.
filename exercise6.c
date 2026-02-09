#include <Stdio.h>
#include <math.h>
#include <conio.h>

void main(){
    int A, B=0, S, i;

    printf("input A: ");
    scanf("%d", &A);
    printf("input B: ");
    scanf("%d", &B);

    S = 0; i=1;

    while(i <= B){
        S = S + pow(A,i);
        i++;
    }
    printf("%d", S);

    getch();
}