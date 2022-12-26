#include <stdio.h>

int main () {
    printf("Enter the number of rows: ");
    int rows;
    scanf("%d",&rows);
    int gap = rows-1;
    int num = 1;
    for(int i = 1; i <= rows; i++){
        num = i;
        for(int i = 0; i < gap; i++){
            printf(" ");
        }
        gap--;
        for(int j = 1; j <= i; j++){
            printf("%d ", num);
            num++;
        }
        num-=2;
        for(int j = 1; j <i; j++){
            printf("%d ",num);
            num--;
        }
        printf("\n");
    }
    return 0;
}