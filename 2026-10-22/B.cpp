#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=160,P=1e9+7;
int n,a[N],b[N],p[N],q[N],tmp[N];
bool check()
{
    for(int i=1;i<=n;i++)b[i]=0,q[i]=i;
    int m=n,now=1;
    while(m>=3)
    {
        int cnt=0,k=0;
        for(int i=1;i<=m;i++)
        {
            if(i>1&&i<m&&p[q[i]]<p[q[i-1]]&&p[q[i]]<p[q[i+1]])
            {
                b[q[i]]=now;
                cnt++;
            }
            else tmp[++k]=q[i];
        }
        if(!cnt)break;
        m=k;
        for(int i=1;i<=m;i++)q[i]=tmp[i];
        now++;
    }
    for(int i=1;i<=n;i++)
        if(a[i]!=-1&&a[i]!=b[i])return false;
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],p[i]=i;
    int ans=0;
    do
    {
        ans+=check();
        if(ans>=P)ans-=P;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans<<endl;
    return 0;
}
