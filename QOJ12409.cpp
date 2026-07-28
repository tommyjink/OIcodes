#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105;
int m,L,nxt[N];
string a;
struct node
{
    string l,r;
    int len,cnt;
}f[61][2];
int cal(string s,string t)
{
    s=" "+s,t=" "+t;
    int n=s.length()-1,m=t.length()-1,res=0;
    for(int i=0;i<=m;i++)nxt[i]=0;
    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&t[j+1]!=t[i])j=nxt[j];
        if(t[j+1]==t[i])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=n;i++)
    {
        while(j&&t[j+1]!=s[i])j=nxt[j];
        if(t[j+1]==s[i])j++;
        if(j==m)res++,j=nxt[j];
    }
    return res;
}
node merge(node x,node y)
{
    if(!x.len)return y;
    if(!y.len)return x;
    node res={x.l+y.l,x.r+y.r,x.len+y.len,x.cnt+y.cnt+cal(x.r+y.l,a)};
    if(res.l.length()>m-1)res.l=res.l.substr(0,m-1);
    if(res.r.length()>m-1)res.r=res.r.substr(res.r.length()-m+1);
    return res;
}

void init()
{
    f[0][0]={"0","0",1,0};
    f[0][1]={"1","1",1,0};
    if(m==1)f[0][0].l=f[0][0].r=f[0][1].l=f[0][1].r="";
    if(a=="0")f[0][0].cnt++;
    if(a=="1")f[0][1].cnt++;
    for(int i=1;i<=60;i++)
    {
        f[i][0]=merge(f[i-1][0],f[i-1][1]);
        f[i][1]=merge(f[i-1][1],f[i-1][0]);
    }
}
node get(int k,int len,int mode)
{
    if(len==0)return{};
    if(len==(1ll<<(k)))return f[k][mode];
    if(len<=(1ll<<(k-1)))return get(k-1,len,mode);
    return merge(f[k-1][mode],get(k-1,len-(1ll<<(k-1)),mode^1));
}
void solve()
{
    cin>>m>>L;
    a.clear();
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        a.push_back('0'+x);
    }
    init();
    cout<<get(60,L+m,0).cnt<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve(); 
    return 0;
}