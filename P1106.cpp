#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s;
int a[1000],k,n,p=1,tag=0,cnt=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>k;
    n=s.length();
    for(int i=1;i<=n;i++)
        a[i]=s[i-1]-'0';
    while(k)
    {
        int t=p;
        if(p+k>n)
            return 0;
        for(int i=p;i<=p+k;i++)
            if(a[i]<a[t])
                t=i;
        if(a[t]!=0)
            tag=true;
        if(a[t]!=0||tag)
            cout<<a[t],cnt++;
        k-=t-p;
        p=t+1;
        // cout<<k<<" "<<p<<" "<<t<<endl;
    }
    for(int i=p;i<=n;i++)
        cout<<a[i],cnt++;
    if(!cnt)cout<<"0";
    return 0;
}