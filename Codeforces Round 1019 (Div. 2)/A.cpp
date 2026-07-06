#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e3+10;
int n,a[N],tag[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        memset(tag,0,sizeof(tag));
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],tag[a[i]]++;
        for(int i=1;i<=n;i++)
            if(tag[i])ans++;
        cout<<ans<<endl;
    }
    return 0;
}