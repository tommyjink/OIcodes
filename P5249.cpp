#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt=4;
    double ans=0.0;
    for(int i=2;i<=100;i+=cnt)
    {
        double tmp=1.0;
        for(int j=1;j<=i;j++)
            tmp*=0.5;
        ans+=tmp;
        if(!cnt)break;
        cnt--;
    }
    cout<<ans<<endl;
    return 0;
}
/*
0.5 3 2
0.28571429
*/