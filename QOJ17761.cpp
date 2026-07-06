#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int ans[N],tag[N];
void cal(int s)
{
    vector<int> v1,v2;
    int cnt=0;
    for(int i=0;i<=8;i++)
        if(s&(1ll<<i))
        {
            cnt++;
            v1.push_back(i);
            if(i==6)v1.push_back(9);
        }
    if(cnt>6)return;
    cnt=0;
    for(int i=9;i<=17;i++)
        if(s&(1ll<<i))
        {
            cnt++;
            v2.push_back(i-9);
            if(i-9==6)v2.push_back(9);
        }
    if(cnt>6)return;
    for(auto x:v1)
    {
        for(auto y:v2)
        {
            tag[x*10+y]=true;
        }
    }
    for(auto x:v2)
    {
        for(auto y:v1)
        {
            tag[x*10+y]=true;
        }
    }
    int now=0;
    while(tag[now])now++;
    ans[now]=s;
    for(auto x:v1)
    {
        for(auto y:v2)
        {
            tag[x*10+y]=false;
        }
    }
    for(auto x:v2)
    {
        for(auto y:v1)
        {
            tag[x*10+y]=false;
        }
    }
}
void solve()
{
    int x;cin>>x;
    if(ans[x]==0)cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
        vector<int> v1,v2;
        for(int i=0;i<=8;i++)if(ans[x]&(1ll<<i))v1.push_back(i);
        for(int i=9;i<=17;i++)if(ans[x]&(1ll<<i))v2.push_back(i-9);
        for(int i=0;i<6;i++)cout<<v1[min(i,(int)(v1.size())-1)]<<" ";
        for(int i=0;i<6;i++)cout<<v2[min(i,(int)(v2.size())-1)]<<" ";
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<(1ll<<18);i++)cal(i);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}