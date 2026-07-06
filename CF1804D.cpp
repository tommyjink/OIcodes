#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],minans=0,maxans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int sum=0;
        for(int j=1;j<=m;j++)
            a[j]=s[j-1]-'0',sum+=a[j];
        int j=1,cnt1=0,cnt2=0;
        while(j<m)
        {
            if(a[j]+a[j+1]!=2)cnt1++,j++;
            j++;
        }
        j=1,cnt2=0;
        while(j<m)
        {
            if(a[j]+a[j+1]==2)cnt2++,j++;
            j++;
        }
        minans+=sum-min(m/4,cnt2);
        maxans+=sum-max(0ll,m/4-cnt1);
    }
    cout<<minans<<" "<<maxans<<endl;
    return 0;
}