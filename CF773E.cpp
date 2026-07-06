#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e6+10;
int n,p,r,x;
int f[N];
bool v[N];
int *fa=f+N/2;
bool *vis=v+N/2;
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=-1000000;i<=1000000;i++)
        fa[i]=i;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        x=find(x);
        vis[x]=true;
        fa[x]=fa[x-1];
        if(x==p)r++;
        else if(x<p)
        {
            r++;
            if(p+r==1)
            {
                if(!vis[p])p--;
            }
            else
            {
                p--;
                r--;
            }
        }
        cout<<p+i-r<<endl;
    }
    return 0;
}
