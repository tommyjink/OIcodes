#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,nxtL[N],nxtR[N];
string s,t;
void solve()
{
    cin>>s;
    n=s.length();
    s=" "+s;
    nxtL[n+1]=n+1;
    nxtR[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='L')nxtL[i]=i;
        else nxtL[i]=nxtL[i+1];
        if(s[i]=='R')nxtR[i]=i;
        else nxtR[i]=nxtR[i+1];
    }
    int q;cin>>q;
    while(q--)
    {
        cin>>t;
        m=t.length();
        t=" "+t;
        if(s[1]=='L'&&t[1]=='R'){cout<<"NO"<<endl;continue;}
        if(s[n]=='R'&&t[m]=='L'){cout<<"NO"<<endl;continue;}
        int p=1,tag=1;
        for(int i=1;i<=m;i++)
        {
            if(t[i]=='L')p=nxtL[p];
            else p=nxtR[p];
            if(p==n+1){tag=0;break;}
            p++;
        }
        if(tag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}