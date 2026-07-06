#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt0=0,cnt1=0;
        string s;
        cin>>n>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
                cnt0++;
            else cnt1++;
        }
        cout<<cnt0+cnt1*(n-1)<<endl;
    }
    return 0;
}
