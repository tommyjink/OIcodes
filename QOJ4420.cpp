#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=200005;
const int B=2048;
int n,m,q,qu[N],qv[N],ql[N],qr[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;
		int head[N],to[N],nxt[N];
		fill(head+1,head+n+1,-1);
		for(int i=1;i<=m;i++)
		{
			int u,v;cin>>u>>v;
			to[i]=v,nxt[i]=head[u],head[u]=i;
		}
		for(int i=0;i<q;i++)cin>>qu[i]>>qv[i]>>ql[i]>>qr[i];
		vector<char> ans(q);
		for(int st=0;st<q;st+=B)
		{
			int sz=min(B,q-st),W=(sz+63)>>6;
			vector<unsigned long long> ev((m+2)*W),can((m+1)*W),f((n+1)*W);
			for(int j=0;j<sz;j++)
			{
				int qi=st+j,w=j>>6,b=j&63;
				unsigned long long bit=1ull<<b;
				int l=ql[qi],r=qr[qi],v=qv[qi];
				ev[l*W+w]^=bit,ev[(r+1)*W+w]^=bit;
				f[v*W+w]|=bit;
			}
			vector<unsigned long long> cur(W);
			for(int c=1;c<=m;c++)
				for(int w=0;w<W;w++)
					cur[w]^=ev[c*W+w],can[c*W+w]=cur[w];
			for(int x=n;x>=1;x--)
				for(int e=head[x];e!=-1;e=nxt[e])
				{
					int y=to[e];
					for(int w=0;w<W;w++)
						f[x*W+w]|=f[y*W+w]&can[e*W+w];
				}
			for(int j=0;j<sz;j++)
			{
				int qi=st+j,w=j>>6,b=j&63;
				ans[qi]=(f[qu[qi]*W+w]>>b)&1;
			}
		}
		for(int i=0;i<q;i++)cout<<(ans[i]?"YES":"NO")<<endl;
	}
	return 0;
}
