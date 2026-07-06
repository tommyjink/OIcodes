#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int t,n,m,l,v,p[N];
struct node
{
	int l,r;
}car[N];
bool bet(int ll,int rr)
{
	int p1=lower_bound(p+1,p+1+m,ll)-p;
	int p2=upper_bound(p+1,p+1+m,rr)-p-1;
	if(p1>0&&p1<=m&&p2>0&&p2<=m&&p1<=p2)
		return 1;
	return 0;
}
bool cmp(node x,node y){return x.l<y.l;}
signed main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l>>v;
		int ans1=0,ans2=0,tr=-1;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(z==0)
			{
				if(y>v)
					car[i]=(node){x,l};
				else car[i]=(node){-1,-1};
			}
			if(z>0)
			{
				if(y>v)
					car[i]=(node){x,l};
				else
				{
					int o=x+((v*v-y*y+(2*z-1))/(2*z));
					if(o>l)car[i]=(node){-1,-1};
					else if((v*v-y*y)%(2*z)==0)
					{
						car[i]=(node){o+1,l};
					}
					else
					{
						car[i]=(node){o,l};
					}
				}
			}
			if(z<0)
			{
				if(y<=v)
					car[i]=(node){-1,-1};
				else
				{
					int o=x+((v*v-y*y)/(2*z));
					if((v*v-y*y)%(2*z)==0)
					{
						car[i]=(node){x,min(l,o-1)};
					}
					else
					{
						car[i]=(node){x,min(l,o)};
					}
				}
			}
			if(car[i].l>car[i].r)car[i]=(node){-1,-1};
		}
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(car+1,car+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			// cout<<car[i].l<<"!!"<<car[i].r<<endl;
			if(car[i].l==-1)continue;
			if(bet(car[i].l,car[i].r))
				ans1++;
			else continue;
			if(car[i].l>tr||!bet(car[i].l,min(car[i].r,tr)))
			{
				ans2++;
				tr=car[i].r;
			}
			else tr=min(tr,car[i].r);
			// cout<<" "<<tr<<endl;
		}
		cout<<ans1<<" "<<m-ans2<<endl;
	}
	return 0;
}