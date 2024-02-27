#include<stdio.h>
int main()
{
	int n,sum,i,temp,r;
	printf("The Armstrong number in b/w 1-500 \n\n\n");

	for(i=1;i<=500;i++)
	{
		temp=i;
		sum=0;
		while(temp>0)
		{
			r=temp%10;
			sum=sum+(r*r*r);
			temp=temp/10;
		}

		if (sum==i)
			printf("%d\n",i);
	}
	return 0;
}
