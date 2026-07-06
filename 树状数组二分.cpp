#include<bits/stdc++.h>
#define endl "\n"
#define pii pair<int,int>
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5e6+10,M=2e6+10,V=5e6;
int m,t[N],cnt[N],a[M],tot;
void add(int x,int d)
{
    for(int i=x;i<=V;i+=lowbit(i))
        t[i]+=d;
}
int query(int k,int x)
{
    int now=x;
    while(now)
    {
        if(t[now]>=k)
        {
            k=t[now]-k+1;
            int p=now-lowbit(now);
            for(int i=lowbit(now)>>1;i;i>>=1)
                if(t[p+i]<k)k-=t[p+i],p+=i;
            return V-p;
        }
        k-=t[now];
        now-=lowbit(now);
    }
    return -1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>m)
    {
        tot=0;
        for(int i=1;i<=m;i++)
        {
            int op,x,k;
            cin>>op>>x;
            if(op==0)
            {
                if(!cnt[x])a[++tot]=x;
                cnt[x]++;
                add(V-x+1,1);
            }
            else if(op==1)
            {
                if(!cnt[x])cout<<-1<<endl;
                else cnt[x]--,add(V-x+1,-1);
            }
            else
            {
                cin>>k;
                cout<<query(k,V-x)<<endl;
            }
        }
        for(int i=1;i<=tot;i++)
        {
            add(V-a[i]+1,-cnt[a[i]]);
            cnt[a[i]]=0;
        }
    }
    return 0;
}
