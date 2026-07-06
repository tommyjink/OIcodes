#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int f[30][10],a[30];
int dfs(int pos,int pre,bool limit)
{
    if(pos==0)return 1;
    if(!limit&&f[pos][pre])return f[pos][pre];
    int up=limit?a[pos]:9,res=0;
    for(int i=0;i<=up;i++)
    {
        if(i==4)continue;
        if(pre==1&&i==3)continue;
        res+=dfs(pos-1,i,limit&&i==up);
    }
    if(!limit)f[pos][pre]=res;
    return res;
}
int F(int x,bool mode)
{
    int cnt=0;
    while(x)a[++cnt]=x%10,x/=10;
    if(mode)for(int i=1;i<=cnt;i++)if(a[i]==4)return -1;
    if(mode)for(int i=1;i<cnt;i++)if(a[i]==3&&a[i+1]==1)return -1;
    return dfs(cnt,0,true)-1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        int op,x;
        cin>>op>>x;
        if(op==1)
        {
            cout<<F(x,true)<<endl;
        }
        else
        {
            int l=0,r=(int)1e18;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(F(mid,false)<x)l=mid+1;
                else r=mid;
            }
            cout<<l<<endl;
        }
    }
    return 0;
}