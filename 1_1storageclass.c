#include<stdio.h>
 int a,b;
 void display()
 {
    int c;
    printf("%d is a local variable\n",c);
 }
 void stat()
 {
    static int d=10;
    printf("%d\n",d);
    d++;
 } 
 void reg()
 {
    register int r;
    printf("%d is a register variable",r);

 }
 int main()
 {
    printf("%d and %d is global variables\n",a,b);
    display();
    stat();
    stat();
    reg();
    return 0;
 }