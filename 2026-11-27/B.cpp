#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define tqss ppt
#define ppt pii
using namespace std;
using ppt=pair<int,int>;
const int N=4e5+10,M=1e10+1;
int n;
pii a[N];
pii cov(pii a,pii b)
{
    return {max(a.first,b.first),min(a.second,b.second)};
}
void print(pii x)
{
    cout<<x.first<<"~"<<x.second<<endl;
}
bool check1(int mid)
{
    // cout<<mid<<":"<<endl;
    pii now=a[1],x,y;
    for(int i=2;i<=n;i++)
    {
        
        x=cov({now.first+mid,M},a[i]);
        y=cov({-M,now.second-mid},a[i]);
        // print(x),print(y);
        if(x.first<=x.second)now=x;
        if(y.first<=y.second)now=y;
        if(x.first>x.second&&y.first>y.second)
    }
    return true;
}
bool check2(int mid)
{
    // cout<<mid<<":"<<endl;
    pii now=a[1];
    for(int i=2;i<=n;i++)
    {
        pii x={now.first-mid,now.second+mid};
        now=cov(x,a[i]);
        if(now.second<now.first)return false;
    }
    return true;
} 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    // check1(5);
    // return 0;
    int l=0,r=M;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check1(mid))l=mid;
        else r=mid-1;
    }
    int R=l;
    l=0,r=M;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check2(2*mid))r=mid;
        else l=mid+1;
    }
    int L=l;
    // cout<<L<<" "<<R<<"!"<<endl;
    if(L<=R)cout<<L<<" "<<R<<endl;
    else cout<<-1<<endl;
    return 0;
}