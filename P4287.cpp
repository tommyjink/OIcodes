#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+10;
int n,f[N],A[N],B[N],ans=0;
string s,t="SS";
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    for(auto c:s)
        t+=c,t+="S";
    int len=t.length()-1,mid=0,r=0;
    for(int i=1;i<=len;i++)
    {
        if(t[i]!='S')continue;
        if(i<r)f[i]=min(f[mid*2-i],r-i+1);
        while(t[i-f[i]]==t[i+f[i]])f[i]++;
        if(i+f[i]-1>=r)r=i+f[i]-1,mid=i;
    }
    for(int i=1;i<=len;i++)
        A[i]=max(A[i-1],i-f[i]/2);
    // for(int i=1;i<=len;i++)
    //     if(t[i]=='S')cout<<i<<":"<<t[i]<<","<<A[i]<<endl;
    // cout<<endl;
    int ans=0;
    for(int i=1;i<=len;i++)
    {
        if(t[i]!='S')continue;
        B[i]=lower_bound(A+i,A+1+len,i+1)-A-1;
        cout<<i<<","<<i+f[i]-1<<endl;
        if(B[i]>i+f[i]-1||B[i]<i)B[i]=0;
        // cout<<i<<","<<B[i]<<endl;
        if(B[i])ans=max(ans,(B[i]-i)*2);
    }

    for(int i=1;i<=len;i++)
        cout<<t[i]<<" ";
    cout<<endl;
    for(int i=1;i<=len;i++)
        cout<<f[i]<<" ";
    cout<<endl;
    for(int i=1;i<=len;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    for(int i=1;i<=len;i++)
        cout<<B[i]<<" ";
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
/*
5
caaaa

*/