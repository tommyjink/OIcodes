#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int n,m,g;
int tot,head[N];
int dfn[N],low[N],num;
int stk[N],top=0,col[N],cnt;
int siz[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
int cal(int x,int y)
{
    return (x-1)*m+y;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    stk[top++]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v])tarjan(v),low[x]=min(low[x],low[v]);
        else if(!col[v])low[x]=min(low[x],dfn[v]);
    }
    if(dfn[x]==low[x])
    {
        cnt++;
        while(1)
        {
            int t=stk[--top];
            col[t]=cnt;
            siz[cnt]++;
            if(t==x)break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>g;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            int k=0;
            if(s[j-1]=='N'||s[j-1]=='n')k=0;
            if(s[j-1]=='S'||s[j-1]=='s')k=1;
            if(s[j-1]=='W'||s[j-1]=='w')k=2;
            if(s[j-1]=='E'||s[j-1]=='e')k=3;
            int x=cal(i,j),y=cal(i+dx[k],j+dy[k]);
            add(x,y);
        }   
    }
    for(int i=1;i<=n*m;i++)
        if(!dfn[i])tarjan(i);
    for(int i=1;i<=cnt;i++)

    return 0;
}