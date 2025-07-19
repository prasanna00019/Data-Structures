#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
#define N 200
int precedence(char operator) { //TO KNOW WHAT IS PRECEDENCE WE USE THIS FUNCTION
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    if (operator == '^')  
        return 3; 
    return 0;
}

char pop(char stack[], int *tos) { //POP OPERATION 
    char value;
    if (*tos < 0) {
        printf("STACK IS EMPTY \n");
        return -1;
    }
    value = stack[*tos];
    (*tos)--;
    return value;
}

void push(char stack[], int *tos, char value) { //PUSH OPERATION 
    if (*tos >= N - 1) {
        printf("STACK IS FULL \n");
        return;
    }
    (*tos)++;
    stack[*tos] = value;
}

char readTop(char stack[], int tos) { //READS TOP OF THE STACK symbol tosSymbol
    if (tos < 0) {
        printf("STACK IS EMPTY \n");
        return -1;
    }
    char temp = stack[tos];
    return temp;
}
bool leftasso(char c){   //THIS FUNCTION IS TO CHECK LEFT OR RIGHT ASSOCIATIVITY 
 if(c=='^'){
  return false;
 }
 else{
  return true;
 }
}
int main() {
    char stack[N];    
    int tos = -1;
    char infix[] = "var1+var2*100-12/var3";
    int length = strlen(infix);
    char* postfix = (char*)malloc((length + 1) * sizeof(char));
    int i, j = 0;
    char input, tosSymbol;
    printf("INPUT INFIX EXPRESSION IS : %s \n", infix);
    
    for (i = 0; i < length; i++) {
        input = infix[i];
        if (isalnum(input))
            postfix[j++] = input;
        else if (input == '(')
            push(stack, &tos, input);
        else if (input == ')') {
            while ((tosSymbol = pop(stack, &tos)) != '(')
                postfix[j++] = tosSymbol;
        } 
        
         else {
            tosSymbol = readTop(stack, tos);
            if (tosSymbol == -1 || tosSymbol == '(')
                push(stack, &tos, input);
            else {
                if (precedence(input) > precedence(tosSymbol))
                    push(stack, &tos, input);
                else if(leftasso(tosSymbol)==true){
                    while (tos >= 0 && precedence(input) <= precedence(readTop(stack, tos)))
                        postfix[j++] = pop(stack, &tos);
                    push(stack, &tos, input);
                }
                else{
                    if(tos>=0 && leftasso(tosSymbol)==false && precedence(input) == precedence(readTop(stack, tos)))
                    {
                    push(stack, &tos, input);
                    }
                    else if(precedence(input) < precedence(readTop(stack, tos)))
                    {
                    if(tos==0){
                        postfix[j++]=pop(stack, &tos);
                        push(stack, &tos, input);
                        
                    }
                    else{
                        while (precedence(input) <= precedence(readTop(stack, tos)))
                            postfix[j++]=pop(stack, &tos);
                            push(stack, &tos, input);
                        }
                       }
                      }
                    }
                   }
                   }
    
    while ((tosSymbol = pop(stack, &tos)) != -1)
        postfix[j++] = tosSymbol;
    
    postfix[j] = '\0';
    printf("POSTFIX EXPRESSION OUTPUT : %s \n", postfix);
    
    return 0;
}
/*
OUTPUT OF PROGRAM IS :
INPUT INFIX EXPRESSION IS : var1+var2*100-12/var3 
STACK IS EMPTY 
STACK IS EMPTY 
POSTFIX EXPRESSION OUTPUT : var1var2100*+12var3/- 

*/




