#include<stdio.h>

int arr[5]={1,2,3,4,5};
int i,count;
int main(){
    for(i=0;i<5;i++)
    {
        if(arr[i]==9)
        {
            count++;
        }
    }
    if(count>0){
        printf("%d ocuurance of the element",count);
    }
    else{
        printf("\n element not found");
    }
}