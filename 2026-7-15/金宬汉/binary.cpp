#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,ls[N],rs[N];
int p[N],inv2,ans[N];
char mode[N];
inline int mod(int x)
{
    if(x>=0)return x%P;
    return (x%P+P)%P;
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
void dfs(int x)
{
    if(x<=n)
    {
        p[x]=inv2;
        return;
    }
    dfs(ls[x]);
    dfs(rs[x]);
    int A=p[ls[x]];
    int B=p[rs[x]];
    if(mode[x]=='&')p[x]=mod(A*B);
    if(mode[x]=='|')p[x]=mod(mod(A+B-mod(A*B)));
    if(mode[x]=='^')p[x]=mod(A+B-mod(2ll*A*B));
}
void dfs1(int x,int now)
{
    // cout<<x<<" "<<mode[x]<<":"<<now<<endl;
    if(x<=n)
    {
        ans[x]=now;
        return;
    }
    if(mode[x]=='^')
    {
        dfs1(ls[x],now);
        dfs1(rs[x],now);
    }
    if(mode[x]=='&')
    {
        dfs1(ls[x],now*p[rs[x]]%P);
        dfs1(rs[x],now*p[ls[x]]%P);
    }
    if(mode[x]=='|')
    {
        // cout<<rs[x]<<"...."<<mod(1-rs[x])<<endl;
        dfs1(ls[x],mod(now*mod(1-p[rs[x]])));
        dfs1(rs[x],mod(now*mod(1-p[ls[x]])));
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    inv2=qpow(2,P-2);
    cin>>n;
    string s;
    cin>>s;
    stack<int> q;
    stack<char> g;
    int now=0,num=n;
    for(auto c:s)
    {
        if(c=='^'||c=='&'||c=='|')g.push(c);
        if(c=='(')continue;
        if(c=='x')q.push(++now);
        if(c==')')
        {
            int x=q.top();q.pop();
            int y=q.top();q.pop();
            q.push(++num);
            ls[num]=y;
            rs[num]=x;
            mode[num]=g.top();g.pop();
        }
    }
    dfs(num);
    dfs1(num,1);
    // cout<<inv2<<endl;
    // for(int i=1;i<=num;i++)
    //     cout<<p[i]<<endl;
    // cout<<"___"<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    // cout<<"!!!"<<mod(3*qpow(4,P-2));
    return 0;
}