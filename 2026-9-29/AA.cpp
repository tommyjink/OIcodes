#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int n,nxt[N];
string s,t;
void solve()
{
    cin>>n>>s;
    s=" "+s;
    int p=1;
    while(p<=n&&s[p]-'0'==0)p++;
    if(p==n+1){cout<<"0"<<endl;return;}
    int q=p;
    while(q<=n&&s[q]-'0'==1)q++;
    // cout<<p<<","<<q<<"?"<<endl;
    if(q==n+1)
    {
        if(p==1)
        {
            for(int i=p;i<n;i++)cout<<"1";
            cout<<"0"<<endl;
            return;
        }
        for(int i=p;i<=n;i++)cout<<"1";
        cout<<endl;
        return;
    }
    t=" ";
    for(int i=q;i<=n;i++)t.push_back(1-s[i]+2*'0');
    // cout<<t<<"?"<<endl;
    int m=t.length()-1;
    for(int i=1;i<=m;i++)nxt[i]=0;
    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&t[i]!=t[j+1])j=nxt[j];
        if(t[i]==t[j+1])j++;
        nxt[i]=j;
    }
    int ans=0;
    for(int i=1,j=0;i<=n;i++)
    {
        while(j&&s[i]!=t[j+1])j=nxt[j];
        if(s[i]==t[j+1])j++;
        ans=max(ans,j);
    }
    // cout<<ans<<"!"<<endl;
    for(int i=p;i<=n;i++)
    {
        if(i-q+1<=ans)cout<<"1";
        else cout<<s[i];
    }
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}