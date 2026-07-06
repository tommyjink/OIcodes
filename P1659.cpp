#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e6+10,P=19930726;
int n,K,f[N],r=0,mid=0,cnt[N],ans=0,fin=1,tot=0;
string s,t="SS";
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    cin>>n>>K>>s;
    for(int i=0;i<n;i++)
        t+=s[i],t+='S';
    for(int i=1;i<=t.length();i++)
    {
        if(i<=r)f[i]=min(f[mid*2-i],r-i+1);
        while(t[i+f[i]]==t[i-f[i]])f[i]++;
        if(i+f[i]-1>r)r=i+f[i]-1,mid=i;
        if((f[i]-1)%2==0)continue;
        cnt[f[i]-1]++,ans=max(ans,f[i]-1);
    }
    for(int i=n;i>=0;i--)
        cnt[i]+=cnt[i+2],tot+=cnt[i];
    // for(int i=1;i<=n;i++)
    //     printf("cnt[%lld]=%lld\n",i,cnt[i]);
    if(tot<K)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for(int i=ans;i>=0&&K>=0;i--)
        fin=(fin*qpow(i,min(K,cnt[i])))%P,K-=min(K,cnt[i]);
    cout<<fin<<endl;
    return 0;
}