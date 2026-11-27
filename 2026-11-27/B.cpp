#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define tqss ppt
#define ppt pii
using namespace std;
using ppt=pair<int,int>;
const int N=4e5+10,M=1e10;
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
    int p=a[1].first;
    for(int i=2;i<=n;i++)
    {
        if(p+mid>a[i].second)return false;
        p=max(a[i].first,p+mid);
    }
    return true;
}
bool check2(int mid)
{
    int p=a[1].second;
    for(int i=2;i<=n;i++)
    {
        if(p+mid<a[i].first)return false;
        p=min(a[i].second,p+mid);
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
    // cout<<check1(123)<<endl;
    // return 0;
    int l=0,r=M;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check1(mid))l=mid;
        else r=mid-1;
    }
    int R=l;
    l=1,r=M;
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