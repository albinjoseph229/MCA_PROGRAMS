#include<stdio.h>
#include<string.h>
#define maxsize 100

int top=-1;
char stack[maxsize];
char a[maxsize];
int i;

void push()
{
    for(i=0;i<strlen(a);i++){
        top++;
        stack[top]=a[i];
    }
}
void pop()
{
    printf("Reversed string is:");
    for(i=top;top>-1;top--){
        printf("%c",stack[top]);
    }
}
int main(){
    printf("enter the string:");
    gets(a);
    push(a);
    pop();
}