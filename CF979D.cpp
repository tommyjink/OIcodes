#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=2e7+10;
int q,nxt[N][2],tot=1e5;
int mn[N];
void insert(int p,int x)
{
    mn[p]=min(mn[p],x);
    for(int i=16;i>=0;i--)
    {
        int c=(x>>i)&1;
        if(!nxt[p][c])nxt[p][c]=++tot;
        p=nxt[p][c];
        mn[p]=min(mn[p],x);
    }
}
int query(int p,int x,int lim)
{
    if(mn[p]>lim)return -1;
    for(int i=16;i>=0;i--)
    {
        int c=(x>>i)&1;
        if(nxt[p][c^1]&&mn[nxt[p][c^1]]<=lim)
            p=nxt[p][c^1];
        else p=nxt[p][c];
        if(mn[p]>lim)return -1;
    }
    return mn[p];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(mn,63,sizeof(mn));
    int q;
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x;
            for(int i=1;i*i<=x;i++)
                if(x%i==0)
                    insert(i,x),
                    insert(x/i,x);
        }
        else
        {
            int x,k,s;
            cin>>x>>k>>s;
            if(x%k)cout<<"-1"<<endl;
            else cout<<query(k,x,s-x)<<endl;
        }
    }
    return 0;
}