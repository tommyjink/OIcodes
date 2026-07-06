#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(c<b)c+=24;
	for(int i=b;i<=c;i++)
		if(i==a||i%24==a)
		{
			cout<<"No"<<endl;
			return 0;
		}
	cout<<"Yes";
	return 0;
}