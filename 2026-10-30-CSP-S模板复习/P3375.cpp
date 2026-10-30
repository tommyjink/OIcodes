#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,nxt[N];
string s,t;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>t;
    n=s.length();
    m=t.length();
    s=" "+s;
    t=" "+t;
    for(int now=0,i=2;i<=n;i++)
    {
        while(now&&s[now+1]!=s[i])now=nxt[now];
    }
    return 0;
}