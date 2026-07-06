#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int T,n,k,s[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=0;i<=n;i++) s[i]=0;
        if(k>n*(n+1)/2)
        {
            for(int i=1;i<=n;i++) cout<<0<<" ";
            cout<<endl;
            continue;
        }
        if(k<n)
        {
            s[n-k+1]=n*(n+1)/2;
            for(int i=1;i<k;i++) s[n-i+1]++,s[n-k+1]--;
            for(int i=1;i<=n;i++) cout<<s[i]-s[i-1]<<" ";
            cout<<endl;
            continue;
        }
        k-=n;
        int i,p=1;
        for(i=1;i<=n;i++)
        {
            int v=n-i;
            if(k>v) k-=v,s[i]=i;
            else
            {
                s[n-k]=i;
                break;
            }
        }
        for(int j=n;j>=i;j--)
        {
            while(s[p]) p++;
            s[p]=j;
        }
        for(int i=1;i<=n;i++) cout<<s[i]-s[i-1]<<" ";
        cout<<endl;
    }
    return 0;
}