// 371=3^3+7^3+1^3 = 27+343+1 = 371 Armstrong number

#include<stdio.h>
int main()
{
  int n,r,sum=0,temp;
  printf("Enter number:");
  scanf("%d",&n);
  temp=n;
  while(n>0)
  
  {
    r=n%10;
    sum=sum+(r*r*r);
    n=n/10;
  }
 
 if (temp==sum)
 printf("armstrong number\n");
 else
 printf("not armstrong number\n");
 return 0;
 }

