#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int k=1e9+7;
int n,m,l,f[2][28][28][2],g[2][28][28][2],a[1000007];
int b1[25007][28],b2[25007][28],r1[25007],r2[25007],ans,nf[25007][28][2],ng[25007][28][2];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;a[0]=-1e18;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int ts=m+2;
		for(int j=m+1;j>=1;j--)if(a[b1[i-1][j]]<a[i])b1[i][j+1]=b1[i-1][j],ts=j;
		b1[i][ts]=i;r1[i]=ts;
		for(int j=1;j<=ts-1;j++)b1[i][j]=b1[i-1][j];
	}
	for(int i=n;i>=1;i--)
	{
		int ts=m+2;
		for(int j=m+1;j>=1;j--)if(a[b2[i+1][j]]<=a[i])b2[i][j+1]=b2[i+1][j],ts=j;
		b2[i][ts]=i;r2[i]=ts;
		for(int j=1;j<=ts-1;j++)b2[i][j]=b2[i+1][j];
	}
	f[0][0][1][0]=g[(n+1)&1][0][1][0]=1;
	for(int i=1;i<=n;i++)
	{
		int fi=i&1;
		for(int j=0;j<=m;j++)for(int o=1;o<=m+1;o++)
			f[fi][j][o][0]=f[fi][j][o][1]=0,f[fi^1][j][o][0]%=k,f[fi^1][j][o][1]%=k;
		for(int j=0;j<=m;j++)
		{
			int q=r1[i],fl=a[i]&1;
			for(int o=1;o<=m+1;o++)
				if(j)
				{
					f[fi][j][o+(o>=q)][(a[b1[i-1][o]]&1)]+=f[fi^1][j-1][o][0];
					f[fi][j][o+(o>=q)][(a[b1[i-1][o]]&1)^1]+=f[fi^1][j-1][o][1];
				}
			for(int o=1;o<=q-1;o++)
			{
				f[fi][j][o][(a[b1[i][o]]&1)^fl]+=f[fi^1][j][o][0];
				f[fi][j][o][(a[b1[i][o]]&1)^1^fl]+=f[fi^1][j][o][1];
			}
			for(int o=q;o<=m+1;o++)
				f[fi][j][q][0]+=f[fi^1][j][o][0],f[fi][j][q][1]+=f[fi^1][j][o][1];
			nf[i][j][0]=f[fi][j][q][0]%k;
			nf[i][j][1]=f[fi][j][q][1]%k;
		}
	}
	for(int i=n;i>=1;i--)
	{
		int fi=i&1;
		for(int j=0;j<=m;j++)for(int o=1;o<=m+1;o++)
			g[fi][j][o][0]=g[fi][j][o][1]=0,g[fi^1][j][o][0]%=k,g[fi^1][j][o][1]%=k;
		for(int j=0;j<=m;j++)
		{
			int q=r2[i],fl=a[i]&1;
			for(int o=1;o<=m+1;o++)
				if(j)
				{
					g[fi][j][o+(o>=q)][(a[b2[i+1][o]]&1)]+=g[fi^1][j-1][o][0];
					g[fi][j][o+(o>=q)][(a[b2[i+1][o]]&1)^1]+=g[fi^1][j-1][o][1];
				}
			for(int o=1;o<=q-1;o++)
			{
				g[fi][j][o][(a[b2[i][o]]&1)^fl]+=g[fi^1][j][o][0];
				g[fi][j][o][(a[b2[i][o]]&1)^1^fl]+=g[fi^1][j][o][1];
			}
			for(int o=q;o<=m+1;o++)
				g[fi][j][q][0]+=g[fi^1][j][o][0],g[fi][j][q][1]+=g[fi^1][j][o][1];
			ng[i][j][0]=g[fi][j][q][0]%k;
			ng[i][j][1]=g[fi][j][q][1]%k;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			ans+=nf[i][j][0]*ng[i][m-j][0];
			ans+=nf[i][j][1]*ng[i][m-j][1];
			ans%=k;
		}
	cout<<ans<<endl;
	return 0;
}
