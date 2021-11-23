#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top = 0;
int stackResult = 0;

void istop (int *stack, int* stack_for_result) {
    if(top == 0){
        stack_for_result[stackResult++] = -1;
    }
    else{
        printf("this is stack[top] = %d\n", stack[top]);
        stack_for_result[stackResult++] = stack[top];
    }
}

void size(int* stack_for_result) {
    stack_for_result[stackResult++] = top;

}

void IsEmpty(int* stack_for_result) {
    if(top == 0){
        stack_for_result[stackResult++] = 1;
    }
    else{
        stack_for_result[stackResult++] = 0;
    }
}

void pop(int* stack, int* stack_for_result){
    if(top == 0)
        stack_for_result[stackResult++] = -1;
    else 
        stack_for_result[stackResult++] = stack[top--];
}

void push(int var, int* stack){
        stack[++top] = var;
}

int main () {
    int stackSize;
    scanf("%d", &stackSize);
    int stack[stackSize];
    int stack_for_result[stackSize];
    char str[10];
    int var;
    for (int i = 0; i < stackSize; i++){
        scanf("%s", str);
        if(strcmp(str,"push") == 0){
            scanf("%d", &var);
            push(var, stack);
        }
        else if (strcmp(str,"pop") == 0){
            pop(stack,stack_for_result);
        }
        else if(strcmp(str,"size") == 0){
            size(stack_for_result);
        }
        else if(strcmp(str,"empty") == 0){
            IsEmpty(stack_for_result);
        }
        else if(strcmp(str,"top") == 0){
            istop(stack, stack_for_result);
        }
        
    }
    for(int i = 0; i < stackResult; i++){
        printf("%d\n", stack_for_result[i]);
    }
}
