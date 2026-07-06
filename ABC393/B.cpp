#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s;
int n,ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n=s.length();
    for(int i=1;i<=n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a=j,b=j+i,c=b+i;
            if(c>=n)continue;
            if(s[a]=='A'&&s[b]=='B'&&s[c]=='C')
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}