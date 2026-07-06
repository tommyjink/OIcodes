#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],sum=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
        sum+=x;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        sum=sum-x*a[x]+y*a[x];
        a[y]+=a[x];
        a[x]=0;
        cout<<sum<<endl;
    }

    return 0;
}
/*
2
1 2
3
1 100
2 100
100 1000
*/