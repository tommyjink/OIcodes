#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int l,r,now,mx,cnt,tot,m;
int a[N],b[N],c[N],id[N],ch[N][2];
int head[N],tail[N];
struct node
{
    int to,next,val;
}e[N];

int addnode()
{
    cnt++;
    ch[cnt][0]=ch[cnt][1]=0;
    head[cnt]=tail[cnt]=0;
    return cnt;
}

void add(int x,int y,int z)
{
    e[++tot]=(node){y,0,z};
    if(!head[x])head[x]=tail[x]=tot;
    else e[tail[x]].next=tot,tail[x]=tot;
}

int calc(int x)
{
    int ans=0;
    while(x)
    {
        ans++;
        x>>=1;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>l>>r;
    now=l;
    while(now<=r)
    {
        int x=now&-now;
        while(now+x-1>r)
            x>>=1;
        int c=0,tmp=x;
        while(tmp>1)
        {
            c++;
            tmp>>=1;
        }
        a[++m]=now>>c;
        b[m]=calc(a[m]);
        ::c[m]=c;
        mx=max(mx,c);
        now+=x;
    }
    int s=addnode(),t=addnode();
    id[0]=t;
    for(int i=1;i<=mx;i++)
        id[i]=addnode();
    for(int i=1;i<=mx;i++)
    {
        add(id[i],id[i-1],0);
        add(id[i],id[i-1],1);
    }
    for(int i=1;i<=m;i++)
    {
        int u=s;
        for(int j=b[i]-1;j>=1;j--)
        {
            int x=(a[i]>>j)&1;
            if(!ch[u][x])
            {
                ch[u][x]=addnode();
                add(u,ch[u][x],x);
            }
            u=ch[u][x];
        }
        add(u,id[c[i]],a[i]&1);
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        int num=0;
        for(int j=head[i];j;j=e[j].next)
            num++;
        cout<<num;
        for(int j=head[i];j;j=e[j].next)
            cout<<" "<<e[j].to<<" "<<e[j].val;
        cout<<endl;
    }
    return 0;
}
