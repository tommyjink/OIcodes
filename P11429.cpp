#include<bits/stdc++.h>
#define int long long
using namespace std;
int n=0;
char now;
string winner="SONJA";
vector<int> a;
vector<string> b;
map<string,int> mp;
map<string,int> ban[1000];
string nxt(string s)
{
	if(s=="IGOR")return "LEA";
	if(s=="LEA")return "MARINO";
	if(s=="MARINO")return "SONJA";
	if(s=="SONJA")return "VIKTOR";
	if(s=="VIKTOR")return "IGOR";
	return "Error";
}
signed main()
{
	cin>>n;
	for(int k=1;k<=n;k++)
	{
		string player=winner,now_maxp,r_maxp;
		int exred=0,now_maxn=0,r_maxn=0,num;
		for(int i=1;i<=5;i++,player=nxt(player))
		{
			string s;
			cin>>s;num=s[1]-'0';
			if(i==1)now=s[0],mp[s]=true;
			else if(mp[s]||ban[(int)s[0]][player])
			{
				a.push_back(k);
				b.push_back(player);
				continue;
			}
			else
			{
				if(s[0]!=now)ban[(int)now][player]=true;
				// cout<<k<<":"<<s[0]<<" "<<player<<" "<<ban[(int)s[0]][player]<<endl;
				mp[s]=true;
			}
			if(s[0]=='C')exred=true;
			if(s[0]==now&&num>now_maxn)
				now_maxn=num,now_maxp=player;
			if(s[0]=='C'&&num>r_maxn)
				r_maxn=num,r_maxp=player;
		}
		if(exred)winner=r_maxp;
		else winner=now_maxp;
		// cout<<k<<" winner:"<<winner<<" "<<r_maxn<<endl;
	}
	cout<<(int)a.size()<<endl;
	for(int i=0;i<(int)a.size();i++)
	{
		cout<<a[i]<<" "<<b[i]<<endl;
	}
	return 0;
}