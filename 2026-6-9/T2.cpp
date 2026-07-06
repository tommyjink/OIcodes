#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,c,h[N],p[N],f[N];
int w(int x,int y)
{
    return (h[x]-h[y])*(h[x]-h[y])+c;
}
// void solve(int L,int R,int l,int r)
// {
//     if(L>R)return;
//     int mid=(L+R)>>1;p[mid]=l;
//     for(int i=l;i<=r;i++)
//         if(w(i,mid)<w(p[l],mid))p[l]=i;
//     solve(L,mid-1,l,p[l]);
//     solve(mid+1,R,p[l],r);
// }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>c;
    for(int i=1;i<=n;i++)cin>>h[i];
    memset(f,64,sizeof(f));
    f[1]=0;
    p[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=p[i-1];j<i;j++)
        {
            if(f[j]+w(j,i)<=f[i])
                f[i]=f[j]+w(i,j),p[i]=j;
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<p[i]<<" ";
    // cout<<endl;
    cout<<f[n]<<endl;
    return 0;
}