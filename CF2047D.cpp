#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6,INF=1e10;
int n,a[N],mina[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    memset(mina,127,sizeof(mina));
    while(t--)
    {
        int mint=INF;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=n;i>=1;i--)
            mina[i]=min(mina[i+1],a[i]);
        for(int i=1;i<=n;i++)
            if(min(mina[i+1],mint)<a[i])
                a[i]++,mint=min(mint,a[i]);
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)mina[i]=INF;
    }
    return 0;
}