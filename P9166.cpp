#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,x,tag[N],t[N];
vector<int> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        if(l<x)tag[l]++;
        if(r>x)tag[r]++;
        t[l]++,t[r]--;
        // cout<<l<<","<<r-1<<endl;
    }
    for(int i=1;i<=n;i++)t[i]+=t[i-1];
    // for(int i=1;i<=n;i++)cout<<t[i]<<" ";
    // cout<<endl;
    for(int i=x;t[i];i++)if(tag[i+1])ans.push_back(i+1);
    for(int i=x-1;t[i];i--)if(tag[i])ans.push_back(i);
    sort(ans.begin(),ans.end());
    for(int i:ans)cout<<i<<" ";
    return 0;
}