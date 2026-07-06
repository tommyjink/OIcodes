#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=500,M=200000;
int n,a[N],d[N],dp[M],q,f1[M],f2[M];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    memset(dp,128,sizeof(dp));
    dp[0]=dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>d[i];
        for(int j=M-1;j>=d[i];j--)
        {
            dp[j]=max({dp[j],dp[j]+a[i]});
            if(j-d[i]>=0)
                dp[j]=max(dp[j],dp[j-d[i]]);
        }
    }
    for(int i=1;i<M;i++)
        f1[i]=max(f1[i-1],dp[i]+i);
    for(int i=M-2;i>=0;i--)
        f2[i]=max(f2[i+1],dp[i]);
    cin>>q;
    int ans1=0,ans2=0,ans3=0;
    while(q--)
    {
        int A,D;
        cin>>A>>D;
        if(f1[A]-A-D>0||f2[A]-D>0)
            ans1++;
        else if(f1[A]-A-D<0&&f2[A]-D<0)
            ans3++;
        else ans2++;
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    return 0;
}

/*
4
2 3
1 1
0 2
5 1
5
5 5
6 5
7 10
10 0
12 0
*/