#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
string s,t;
void solve()
{
    cin>>n>>s;
    s=" "+s;
    int p=1;
    while(p<=n&&s[p]=='0')p++;
    if(p==n+1){cout<<"0"<<endl;return;}
    int q=p;
    while(q<=n&&s[q]=='1')q++;
    t=s.substr(p);
    if(q==n+1)
    {
        if(p==1)t.back()='0';
        cout<<t<<endl;
        return;
    }
    int r=q;
    while(r<=n&&s[r]=='0')r++;
    int x=q-min(q-p,r-q);
    for(int i=q;i<=n;i++)t[i-p]=(s[i]==s[x+i-q]?'0':'1');
    cout<<t<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
