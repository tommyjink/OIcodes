#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=(1<<20)+10;
int n,cnt[N],f[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int j=0;j<20;j++)
        for(int i=0;i<(1<<20);i++)
            if(!(i>>j&1))cnt[i]+=cnt[i|(1<<j)];
    f[(1<<20)-1]=((1<<20)-1)*cnt[(1<<20)-1];
    for(int i=(1<<20)-2;i>=0;i--)
        for(int j=0;j<20;j++)
            if(!(i>>j&1))
            {
                int x=i|(1<<j);
                f[i]=max(f[i],f[x]+i*(cnt[i]-cnt[x]));
            }
    cout<<f[0]<<endl;
    return 0;
}
