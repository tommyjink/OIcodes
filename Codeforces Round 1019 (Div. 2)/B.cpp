#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt01=0,cnt10=0;
        cin>>n>>s;
        s="0"+s;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0'&&s[i]=='1') 
                cnt01++;
            if(s[i-1]=='1'&&s[i]=='0')
                cnt10++;
        }
        if(cnt10>=2||cnt01>=2)cout<<n+cnt10+cnt01-2<<endl;
        else if(cnt01&&cnt10)cout<<n+cnt10+cnt01-1<<endl;
        else cout<<n+cnt10+cnt01<<endl;
    }
    return 0;
}