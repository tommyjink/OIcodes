#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20000;
int tag[N],t;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i*i<=N;i+=2)
        tag[i*i]=true;
    cin>>t;
    while(t--)
    {
        int n,tot=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int x;cin>>x;
            tot+=x;
            if(tag[tot])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}