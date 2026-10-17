#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3000+10;
int n,k,a[N],sum[N],f[N],d[N],q[N],p[N];
int w(int l,int r)
{
    int mid=(l+r)>>1;
    return a[mid]*(mid-l+1)-(sum[mid]-sum[l-1])+(sum[r]-sum[mid])-a[mid]*(r-mid);
}
bool cmp(int x,int y,int pos)
{
    int v1=f[x]+w(x+1,pos),v2=f[y]+w(y+1,pos);
    if(v1!=v2)return v1<v2;
    // 同费用时优先段数多的决策，再取靠右的决策。
    if(d[x]!=d[y])return d[x]>d[y];
    return x>y;
}
int check(int c)
{
    f[0]=d[0]=0;
    int l=1,r=1;
    q[1]=0,p[1]=1;
    for(int i=1;i<=n;i++)
    {
        // p[t] 是决策 q[t] 开始生效的位置。
        while(l<r&&p[l+1]<=i)l++;
        int j=q[l];
        f[i]=f[j]+w(j+1,i)+c;
        d[i]=d[j]+1;
        if(i==n)continue;
        while(l<=r&&cmp(i,q[r],max(i+1,p[r])))r--;
        if(l>r)
        {
            q[++r]=i,p[r]=i+1;
            continue;
        }
        if(!cmp(i,q[r],n))continue;
        int L=max(i+1,p[r]),R=n;
        while(L<R)
        {
            int mid=(L+R)>>1;
            if(cmp(i,q[r],mid))R=mid;
            else L=mid+1;
        }
        q[++r]=i,p[r]=L;
    }
    return d[n];
}
void WQS()
{
    int l=0,r=w(1,n)+1;
    while(l<r)
    {
        int mid=l+(r-l+1)/2;
        if(check(mid)<k)r=mid-1;
        else l=mid;
    }
    check(l);
    cout<<f[n]-k*l<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    WQS();
    return 0;
}
