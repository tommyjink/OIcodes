#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
string s;
int n,a[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
        a[i+1]=s[i]-'0';
    for(int i=1;i<n;i++)
    {
        if(a[i]+1==a[i+1])
        {
            int l=i,r=i+1;
            while(l>=1&&r<=n&&a[l]==a[i]&&a[r]==a[i+1])
                ans++,l--,r++;
        }
    }
    cout<<ans<<endl;
    return 0;
}