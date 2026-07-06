#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=200005;
struct AC
{
	int tr[N][26],fail[N],cnt[N],tot;
	void ins(string s)
	{
		int u=0;
		for(char c:s)
		{
			int v=c-'a';
			if(!tr[u][v])tr[u][v]=++tot;
			u=tr[u][v];
		}
		cnt[u]++;
	}
	void build()
	{
		queue<int> q;
		for(int i=0;i<26;i++)if(tr[0][i])q.push(tr[0][i]);
		while(!q.empty())
		{
			int u=q.front();q.pop();
			cnt[u]+=cnt[fail[u]];
			for(int i=0;i<26;i++)
			{
				if(tr[u][i])fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
				else tr[u][i]=tr[fail[u]][i];
			}
		}
	}
}fw,bw;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string t;cin>>t;
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;cin>>s;
		fw.ins(s);
		reverse(s.begin(),s.end());
		bw.ins(s);
	}
	fw.build(),bw.build();
	int L=t.length();
	vector<int> f1(L+2),f2(L+2);
	int u=0;
	for(int i=0;i<L;i++)u=fw.tr[u][t[i]-'a'],f1[i+1]=fw.cnt[u];
	u=0;
	for(int i=L-1;i>=0;i--)u=bw.tr[u][t[i]-'a'],f2[i+1]=bw.cnt[u];
	int ans=0;
	for(int i=1;i<L;i++)ans+=f1[i]*f2[i+1];
	cout<<ans<<endl;
	return 0;
}
