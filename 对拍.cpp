#include<bits/stdc++.h>
#include<Windows.h>
#define int long long
using namespace std;

signed main()
{
	for(int i=1;i<=2000;i++)
	{
		printf("第%lld次尝试：\n",i);
		system("P9118数据生成.exe");
		system("P9118.exe");
		system("P9118对拍.exe");
		if(system("fc a.txt b.txt"))break;
	}
	printf("出现错误");
	
	
	return 0;
}
