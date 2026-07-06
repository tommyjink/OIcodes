#include<bits/stdc++.h>
using namespace std;
int n,a[1001],tot,dx;
bitset<2500001>b1,b2,d;//b1为正数,b2为负数，d为b1&b2
bool f;
void solve(){
	cin>>n,tot=0,f=0,b1=b2=0;//初始化
	for(int i=1;i<=n;i++)cin>>a[i],tot+=a[i];
	if(tot%n){puts("No");return;}//平均数不为整数
	dx=tot/n;
	for(int i=1;i<=n;i++)a[i]-=dx;
	b1[0]=b2[0]=1;
	for(int i=1;i<=n;i++){
		if(a[i]>0)b1|=(b1<<a[i]);
		else if(a[i]<0)b2|=(b2<<(-a[i]));
		else {puts("Yes"),f=1;break;}//当a[i]=0时以{a[i]}为一个集合即可
	}
	if(!f){
		d=b1&b2;
		if(d.count()<=2)puts("No");//0和最大最小值不能取
		else puts("Yes");
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)solve();
}
