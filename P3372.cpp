#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e6+10;
int n,m,t1[N],t2[N],tot=0;
void add(int p,int w)
{
    for(int i=p;i<=n;i+=lowbit(i))
        t1[i]+=w,t2[i]+=w*p;
}
int query(int p)
{
    int res=0;
    for(int i=p;i;i-=lowbit(i))
        res+=t1[i]*(p+1)-t2[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        add(i,x),add(i+1,-x);
    }
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            int w;cin>>w;
            add(x,w),add(y+1,-w);
        }
        else
        {
            cout<<query(y)-query(x-1)<<endl;
        }
    }
    return 0;
}