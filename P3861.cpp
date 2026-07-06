#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4,M=1e6+10,P=998244353;
int n,f[N][N],b[M],c[M];
vector<int> p;
int F(int x)
{
    if(x<=sqrt(n))
        return b[x];
    else return c[n/x];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        p.clear();
        for(int i=1;i*i<=n;i++)
        {
            if(n%i)continue;
            p.push_back(i);
            if(n/i!=i)p.push_back(n/i);
        }
        sort(p.begin(),p.end());
        int m=p.size();
        for(int i=0;i<m;i++)
            if(p[i]<=sqrt(n))b[p[i]]=i;
            else c[n/p[i]]=i;
        for(int i=0;i<m;i++)
            f[i][0]=0;
        f[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<m;j++)
            {
                f[i][j]=f[i][j-1];
                if(p[i]%p[j]==0)
                    f[i][j]=(f[i][j]+f[F(p[i]/p[j])][j-1])%P;
            }
        }
        cout<<f[m-1][m-1]-1<<endl;
    }
    return 0;
}