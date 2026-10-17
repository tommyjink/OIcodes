#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,q,deg[N],a=0,b=0;
string s;
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
int cal()
{
    if(n==1&&s[1]=='?')return 2;
    if(n==1&&s[1]!='?')return 1;
    if(s[1]=='U'||a)return 0;
    return qpow(2,b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q>>s;
    s=" "+s;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
    }
    for(int i=2;i<=n;i++)
        if(deg[i]==1&&s[i]=='D')a++;
        else if(deg[i]>1&&s[i]=='?')b++;
    cout<<cal()<<endl;
    while(q--)
    {
        int x;
        char y;
        cin>>x>>y;
        if(x==1)s[x]=y;
        else if(deg[x]==1)
        {
            if(s[x]=='D')a--;
            if(y=='D')a++;
            s[x]=y;
        }
        else
        {
            if(s[x]=='?')b--;
            if(y=='?')b++;
            s[x]=y;
        }
        cout<<cal()<<endl;
    }

    return 0;
}