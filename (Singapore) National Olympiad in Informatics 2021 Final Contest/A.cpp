#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
bool cmp(pair<int,int> x,pair<int,int> y)
{
    return (__int128)x.first*y.second<(__int128)y.first*x.second;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    pair<int,int> l={0,1},r={0,1};
    bool tag=false;
    for(int i=1;i<=n-1;i++)
    {
        int A=a[i]-a[i+1];
        int B=b[i+1]-b[i];
        if(B==0)
        {
            if(A<=0)cout<<"NO"<<endl,exit(0);
            continue;
        }
        if(B>0)
        {
            pair<int,int> t={A,B};
            if(!tag||cmp(t,r))r=t,tag=true;
        }
        else
        {
            pair<int,int> t={-A,-B};
            if(cmp(l,t))l=t;
        }
    }
    if(tag&&!cmp(l,r))cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
