#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int maxc=1<<22;
int n;
vector<int> a;
bitset<maxc> has;
void dfs(int i,int sz,int lim,int xs)
{
    if(sz==lim)
    {
        if(has[xs])
        {
            cout<<"Yes"<<endl<<lim*2<<endl;
            exit(0);
        }
        has[xs]=1;
        return;
    }
    if(i==n)return;
    if(n-i-1+sz>=lim)dfs(i+1,sz,lim,xs);
    dfs(i+1,sz+1,lim,xs^a[i]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int lim=1;lim<=n;lim++)
    {
        has.reset();
        dfs(0,0,lim,0);
    }
    cout<<"No"<<endl;
    return 0;
}
