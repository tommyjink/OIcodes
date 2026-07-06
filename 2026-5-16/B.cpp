#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=200005,LIM=80;
int n,k,x[N],y[N],c[N],id[N],rk[N],low[20],lcnt,base;
vector<vector<int> > part;
void dfs(int p,int mx,vector<int> &bel)
{
    // cout<<p<<","<<mx<<","<<bel.size()<<endl;
	if(p==4){part.push_back(bel);return;}
	for(int i=0;i<=mx+1;i++)bel[p]=i,dfs(p+1,max(mx,i),bel);
}
int drop(int mask,int cnt)
{
	int res=0;
	for(int i=0;i<lcnt&&cnt;i++)
		if(!(mask>>i&1))res+=c[low[i]],cnt--;
	return res;
}
vector<int> getcand(int sx,int sy)
{
	vector<pair<int,int> > a(n);
	for(int i=1;i<=n;i++)a[i-1]={sx*x[i]+sy*y[i]+(rk[i]>k?c[i]:0),i};
	sort(a.begin(),a.end(),greater<pair<int,int> >());
	int lim=min(n,LIM);
	vector<int> v;
	for(int i=0;i<lim;i++)v.push_back(a[i].second);
	for(int i=0;i<lcnt;i++)v.push_back(low[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	//cout<<"cand sx="<<sx<<" sy="<<sy<<" sz="<<v.size()<<" top3:";
	//for(int i=0;i<min(3,(int)v.size());i++)cout<<v[i]<<" ";cout<<endl;
	return v;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i]>>c[i],id[i]=i;
	//for(int i=1;i<=n;i++)cout<<i<<": "<<x[i]<<" "<<y[i]<<" "<<c[i]<<endl;
	sort(id+1,id+n+1,[](int a,int b){return c[a]>c[b];});
	for(int i=1;i<=n;i++)rk[id[i]]=i;
	for(int i=1;i<=k;i++)base+=c[id[i]];
	//cout<<"base="<<base<<endl;
	for(int i=k;i>=1&&lcnt<16;i--)low[lcnt++]=id[i];
	//cout<<"lcnt="<<lcnt<<endl;for(int i=0;i<lcnt;i++)cout<<low[i]<<" ";cout<<endl;
	//cout<<"low_c: ";for(int i=0;i<lcnt;i++)cout<<c[low[i]]<<" ";cout<<endl;
	vector<int> bel(4);dfs(0,-1,bel);
    // for(auto cc:part)
    // {
    //     for(auto i:cc)cout<<i<<" ";
    //     cout<<endl;
    // }
	//cout<<"parts="<<part.size()<<" n="<<n<<" k="<<k<<endl;
	int ans=0;
	//if(k==1){for(int i=1;i<=n;i++)ans=max(ans,c[i]);cout<<ans<<endl;return 0;}
	for(auto p:part)
	{
		int m=0;
		for(int i=0;i<4;i++)m=max(m,p[i]+1);
		//cout<<"m="<<m<<" p: ";for(int i=0;i<4;i++)cout<<p[i]<<" ";cout<<endl;
		if(m>k)continue;
		int sx[4]={},sy[4]={};
		for(int i=0;i<4;i++)
		{
			if(i==0)sx[p[i]]++;
			if(i==1)sx[p[i]]--;
			if(i==2)sy[p[i]]++;
			if(i==3)sy[p[i]]--;
		}
		vector<int> cand[4];
		for(int i=0;i<m;i++)cand[i]=getcand(sx[i],sy[i]);
		//for(int i=0;i<m;i++){cout<<"cand["<<i<<"]: ";for(int j:cand[i])cout<<j<<" ";cout<<endl;}
		for(int u:cand[0])
		{
			int ss=sx[0]*x[u]+sy[0]*y[u];
			int ad=(rk[u]>k?c[u]:0),cn=(rk[u]>k);
			int mk=0;
			for(int i=0;i<lcnt;i++)if(u==low[i])mk|=1<<i;
			if(m==1){int tmp=base+ss+ad-drop(mk,cn);ans=max(ans,tmp);/*cout<<"m1 u="<<u<<" val="<<tmp<<endl;*/continue;}
			for(int v:cand[1])if(v!=u)
			{
				int s1=ss+sx[1]*x[v]+sy[1]*y[v];
				int ad1=ad+(rk[v]>k?c[v]:0),cn1=cn+(rk[v]>k);
				int mk1=mk;
				for(int i=0;i<lcnt;i++)if(v==low[i])mk1|=1<<i;
				if(m==2){int tmp=base+s1+ad1-drop(mk1,cn1);ans=max(ans,tmp);/*cout<<"m2 u="<<u<<" v="<<v<<" val="<<tmp<<endl;*/continue;}
				for(int w:cand[2])if(w!=u&&w!=v)
				{
					int s2=s1+sx[2]*x[w]+sy[2]*y[w];
					int ad2=ad1+(rk[w]>k?c[w]:0),cn2=cn1+(rk[w]>k);
					int mk2=mk1;
					for(int i=0;i<lcnt;i++)if(w==low[i])mk2|=1<<i;
					if(m==3){int tmp=base+s2+ad2-drop(mk2,cn2);ans=max(ans,tmp);/*cout<<"m3 u="<<u<<" v="<<v<<" w="<<w<<" val="<<tmp<<endl;*/continue;}
					for(int t:cand[3])if(t!=u&&t!=v&&t!=w)
					{
						int s3=s2+sx[3]*x[t]+sy[3]*y[t];
						int ad3=ad2+(rk[t]>k?c[t]:0),cn3=cn2+(rk[t]>k);
						int mk3=mk2;
						for(int i=0;i<lcnt;i++)if(t==low[i])mk3|=1<<i;
						int tmp=base+s3+ad3-drop(mk3,cn3);ans=max(ans,tmp);
						//cout<<"m4 u="<<u<<" v="<<v<<" w="<<w<<" t="<<t<<" val="<<tmp<<endl;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	//cout<<"ans="<<ans<<endl;
	return 0;
}
