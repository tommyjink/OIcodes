#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,m,in[N],out[N],cnt[N];
int tot,head[N];
vector<int> e[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        in[y]++,out[x]++;
    }
    int cnt0=0,cnt1=0,cnt2=0;
    int p1=0,p2=0;
    for(int i=1;i<=n;i++)
    {
        sort(e[i].begin(),e[i].end());
        if(in[i]==out[i])cnt0++;
        if(in[i]-out[i]==1)cnt1++,p1=i;
        if(out[i]-in[i]==1)cnt2++,p2=i;
    }
    if(cnt0==n)
    {
        int p=1;
        for(int i=1;i<=m+1;i++)
        {
            cout<<p<<" ";
            cnt[p]++;
            if(i!=m+1)p=e[p][cnt[p]-1];
        }
    }
    else if(cnt0==n-2&&cnt1==1&&cnt2==1)
    {
        int p=p2;
        // cout<<p2,exit(0);
        for(int i=1;i<=m+1;i++)
        {
            cout<<p<<" ";
            cnt[p]++;
            if(i!=m+1)p=e[p][cnt[p]-1];
        }
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}