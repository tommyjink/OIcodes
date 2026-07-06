#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n;
string s;
void solve()
{
    cin>>n>>s;
    if(s=="AB")
    {
        cout<<"Alice"<<endl;
        return;
    }
    if(s=="BA")
    {
        cout<<"Bob"<<endl;
        return;
    }
    int cntA=0,cntB=0;
    for(int i=0;i<n;i++)
        if(s[i]=='A')cntA++;
        else cntB++;
    if(cntA==0)
    {
        cout<<"Bob"<<endl;
        return;
    }
    if(cntB==0)
    {
        cout<<"Alice"<<endl;
        return;
    }
    if(s[0]=='A'&&s[n-1]=='A')
    {
        cout<<"Alice"<<endl;
        return;
    }
    if(s[n-1]=='A'&&s[n-2]=='A')
    {
        cout<<"Alice"<<endl;
        return;
    }
    if(cntB==1&&s[n-1]=='B')
    {
        cout<<"Alice"<<endl;
        return;
    }
    cout<<"Bob"<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}