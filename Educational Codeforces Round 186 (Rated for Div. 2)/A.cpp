#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.length()-3;i++)
    {
        if(s[i]=='2'&&s[i+1]=='0'&&s[i+2]=='2'&&s[i+3]=='6')
        {
            cout<<"0"<<endl;
            return;
        }
    }
    for(int i=0;i<s.length()-3;i++)
    {
        if(s[i]=='2'&&s[i+1]=='0'&&s[i+2]=='2'&&s[i+3]=='5')
        {
            cout<<"1"<<endl;
            return;
        }
    }
    cout<<"0"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}