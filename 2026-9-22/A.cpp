#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
string s,t;
int n,pos[N];
void solve()
{
    cin>>n>>t;
    t=" "+t;
    s=" ";
    int m=0;
    for(int i=1;i<=n;i++)
    {
        if(m&&s[m]==t[i])s.pop_back(),m--;
        else s.push_back(t[i]),pos[++m]=i;
    }
    if(!m)
    {
        cout<<"YES 1 1"<<endl;
        return;
    }
    int l=1,r=m;
    while(l<r&&s[l]==s[r])l++,r--;
    int len=r-l+1;
    if(len&1)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<len/2;i++)
        if(s[l+i]!=s[l+len/2+i])
        {
            cout<<"NO"<<endl;
            return;
        }
    int L=(l==1?1:pos[l-1]+1),R=pos[l+len/2-1];
    cout<<"YES "<<L<<" "<<R<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
