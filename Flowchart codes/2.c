#include<stdio.h>  
int main()    
    {    
    int a=10, b=20;      
    printf("\nBefore swap %d,%d",a,b);      
    a=a+b;//a=30 (10+20)    
    b=a-b;//b=10 (30-20)    
    a=a-b;//a=20 (30-10)    
    printf("\nAfter swap %d,%d",a,b);    
    return 0;  
    }   
