#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005;
int p,q,a[N],b[N],n,m,tag[N],cnt[N];
int num[N],ans=0;
int qpow(int x,int y,int P)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
void input()
{
    int A,B,C,D,E,F;
    cin>>p>>q;
    cin>>n>>a[1]>>a[2]>>A>>B>>C;
    cin>>m>>b[1]>>b[2]>>D>>E>>F;
    for(int i=3;i<=n;i++)
        a[i]=((A*a[i-1]%p-B*a[i-2]%p-C)%p+p)%p;
    for(int i=3;i<=m;i++)
        b[i]=(D*b[i-1]+E*b[i-2]+F);
}
signed main()
{
	freopen("test.in","r",stdin);
    freopen("test2.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    // for(int i=1;i<=m;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=m;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(qpow(a[i],b[i],p)<=q)
            {
                ans++;
                // cout<<a[i]<<","<<b[j]<<":"<<qpow(a[i],b[i],p)<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*


输入 
5 3
3 2 2 1 0 4
3 3 2 4 2 1

输出
6


5 3
10 2 2 1 5 4
10 3 1 5 2 1

*/