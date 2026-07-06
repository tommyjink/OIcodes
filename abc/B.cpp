#include<bits/stdc++.h>
using namespace std;

int main()
{
	double n;
	cin>>n;
	int a=n*1000;
	if(a==0)
	{
		printf("0");return 0;
	}
	if(a%1000==0)
	{
		printf("%d",(int)n);return 0;
	}
	if(a%100==0)
	{
		printf("%.1f",n);return 0;
	}
	if(a%10==0)
	{
		printf("%.2f",n);return 0;
	}
	printf("%.3f",n);
	return 0;
}