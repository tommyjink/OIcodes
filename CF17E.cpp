#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=2e6+10,P=51123987;
int n,m,f[N*2],a[N],b[N],sum=0;
string s,t=" #";
void add(int l,int r,int d,int *a)
{
    if(l>r)return;
    // cout<<l<<","<<r<<endl;
    a[l]+=d;
    a[r+1]-=d;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(int i=0;i<n;i++)
        t+=s[i],t+='#';
    m=t.length()-1;
    int mid=0,r=0;
    for(int i=1;i<=m;i++)
    {
        if(i<r)f[i]=min(f[mid*2-i],r-i+1);
        while(t[i+f[i]]==t[i-f[i]])f[i]++;
        if(i+f[i]-1>=r)r=i+f[i]-1,mid=i;
        sum=(sum+f[i]/2)%P;
        add((i-f[i])/2+1,i/2,1,a);
        add(i/2,(i+f[i])/2-1,1,b);
    }
    
    // for(int i=1;i<=m;i++)
    //     cout<<t[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=m;i++)
    //     cout<<f[i]<<" ";
    // cout<<endl;
    for(int i=2;i<=n;i++)
    {
        a[i]=(a[i-1]+a[i])%P;
        b[i]=(b[i-1]+b[i])%P;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=n-1;i>=1;i--)
        a[i]=(a[i]+a[i+1])%P;
    int ans=0;
    if(sum&1)ans=sum%P*((sum-1)/2)%P;
    else ans=(sum/2)%P*(sum-1)%P;
    for(int i=1;i<=n-1;i++)
        ans=((ans-b[i]*a[i+1]%P)%P+P)%P;
    cout<<ans<<endl;
    return 0;
}