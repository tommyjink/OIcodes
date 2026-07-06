#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define s(x) x*(x+1)/2
using namespace std;
const int N=1e5+10;
int f[N],sav[N];
//f[i]：恰好i个子串合法时使用最小空间
//
void init()
{
    memset(f,127,sizeof(f));
    f[0]=0;
    for(int i=1;i<N;i++)
        for(int j=1;s(j)<=i;j++)
            if(f[i-s(j)]+2*j<f[i])
                f[i]=f[i-s(j)]+2*j,sav[i]=j;
}
string dfs(int x)//恰好x个子串合法的字符串
{
    string res="";
    if(x-s(sav[x])==0)
    {
        for(int i=1;i<=sav[x];i++)
            res+="()";
        return res;
    }
    res="("+dfs(x-s(sav[x]))+")";
    for(int i=1;i<sav[x];i++)
        res+="()";
    return res;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    if(f[k]>n)
    {
        cout<<"-1"<<endl;
        return;
    }
    string res=dfs(k);
    while(res.length()<n)
        res+=")";
    cout<<res<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}