#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue(int x){
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x; 
  temp->next = NULL;
  
  if(front == NULL){
    front = rear = temp;
  }
  else{
    rear->next = temp;
    rear = temp;
  }
}

void dequeue(){
  if(front == NULL){
    printf("Queue is empty");
    return;
  }
  
  struct Node *temp = front;
  front = front->next;
  
  if(front == NULL)
    rear = NULL;
  
  printf("Removed element is: %d\n", temp->data);
  free(temp); 
}

void display(){
  struct Node *ptr;
  if(front == NULL){
    printf("Queue is empty\n");
    return;
  }
  
  ptr = front;
  printf("Queue elements: \n");
  
  while(ptr != NULL){
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int main(){

  enqueue(10);
  enqueue(20);
  enqueue(30);
  
  display();
  
  dequeue();
  dequeue();
  
  display();
  
  return 0;
}