#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,M=200;
vector<int> a,ans;
int f[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    for(int i=1;i<=4;i++)
    {
        int m=a.size();
        for(int j=0;j<m;j++)
        {
            a.push_back(a[j]*10+1);
            a.push_back(a[j]*10+2);
            a.push_back(a[j]*10+3);
        }
    }
    memset(f,63,sizeof(f));
    f[0]=0;
    for(int i=0;i<=M;i++)
    {
        printf("f[%lld]=%lld\n",i,f[i]);
        if(f[i]==5)ans.push_back(i);
        for(int j:a)f[i+j]=min(f[i+j],f[i]+1);
    }
    // for(auto i:ans)cout<<i<<" ";

    return 0;
}