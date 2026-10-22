#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
int D(int S,int M)
{
    return max(S%2,2*M-S);
}
void solve()
{
    string s;
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;i++)
        a[i]=s[i]-'0';
    int cnt0=0,cnt1=0,k=1,S=0,M=0,ML=0,MR=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) cnt0=0,cnt1++,S++;
        else cnt1=0,cnt0++;
        if(cnt1>1)b[++k]=1;
        else if(cnt0>1&&b[k])b[++k]=0;
        else if(a[i]==1)b[k]++;
        // cout<<"i="<<i<<":"<<endl;
        // for(int j=1;j<=k;j++)
        //     cout<<b[j]<<" ";
        // cout<<endl;
        M=max(M,b[k]);
        if(k>1)ML=max(ML,b[k]),MR=max(MR,b[k-1]);
        if(i==1)ans^=1*i;
        else if(k==1)
            ans^=i*(2*S-1+(a[1]==0)+(a[i]==0));
        else
        {
            int res=2*D(S,M)+1;
            if(a[1]==1)res=min(res,2*D(S-1,max(b[1]-1,ML))+2);
            if(a[i]==1)res=min(res,2*D(S-1,max(b[k]-1,MR))+2);
            ans^=res*i;
        }
    } 
    cout<<ans<<endl;
    for(int i=0;i<=k;i++)b[i]=0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}