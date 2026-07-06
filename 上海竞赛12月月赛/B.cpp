#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6,M=32;
int t,n,a[N],b[N][M],res[2][M];
int cnt[2],H[N];
void cal_OR(int x,int num)
{
	for(int i=M-1;i>=0;i--)
		res[num][i]=res[num][i]|b[x][i];
}
signed main()
{
	cin>>t;
	while(t--)
	{
		memset(res,0,sizeof(res));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			memset(b[i],0,sizeof(b[i]));
			H[i]=0;
			cnt[0]=cnt[1]=0;
			cin>>a[i];
		}
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=n;i++)
			for(int j=0;j<=M-1;j++)
				if(a[i]&(1LL<<j))
				{
					b[i][j]=1;
					H[i]=max(H[i],j);
				}
				else b[i][j]=0;
		// for(int i=1;i<=n;i++)
		// {
			// for(int j=M-1;j>=0;j--)
				// cout<<b[i][j];
			// cout<<endl;
		// }
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;i++)
		{
			if(res[0][H[i]]&&res[1][H[i]])
			{
				int p1=M-1,p2=M-1;
				for(;p1>=0;p1--)
				{
					if(res[0][p1]&&!b[i][p1])
						break;
				}
				for(;p2>=0;p2--)
				{
					if(res[1][p2]&&!b[i][p2])
						break;
				}
				if(p1<p2)
					cal_OR(i,0);
				else cal_OR(i,1);
			}
			else if(res[0][H[i]])
			{
				if(cnt[1]==0&&H[i]==H[n])
					cal_OR(i,1);
				else cal_OR(i,0),cnt[0]++;
			}
			else 
			{
				if(cnt[0]==0&&H[i]==H[n])
					cal_OR(i,0);
				else cal_OR(i,1),cnt[1]++;
			}
			// cout<<i<<" "<<cnt[0]<<" "<<cnt[1]<<" "<<H[i]<<endl;
			// for(int j=M-1;j>=0;j--)cout<<res[0][j];
			// cout<<endl;
			// for(int j=M-1;j>=0;j--)cout<<res[1][j];
			// cout<<endl;
		}
		for(int i=M-1;i>=0;i--)
		{
			res[0][i]=res[0][i]^res[1][i];
			ans+=res[0][i]*(1LL<<i);
		}
		cout<<ans<<endl;
	}
	return 0;
}