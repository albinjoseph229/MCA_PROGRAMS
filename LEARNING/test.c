#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree * root=NULL;

