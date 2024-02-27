#include<stdio.h>
int main()
{
	int n,temp,sum=0,base=1,r;
	printf("Enter a binary num:");
	scanf("%d",&n);
	temp=n;
	while(n>0)
	{
		r=n%10;
		sum = sum+r*base;
		n=n/10;
		base = base*2;
	}

	printf("The binary number is: %d\t",temp);
	printf("The decimal number is: %d\t",sum);
}
