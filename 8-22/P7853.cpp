//8-22 contest A
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,m,b[N],a[N],ans1=0,ans2=0;
string s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
        b[i+1]=s[i]-'0';
    for(int i=1;i<=m;i++)
        cin>>a[i],b[++a[i]]++;
    for(int i=1;i<=n;i++)
    {
        int now=i,res=1;
        while(b[now]/2)
            ans1+=b[now]/2,res++,b[now+1]+=b[now]/2,b[now]&=1,now++;
        ans2=max(ans2,res);
    }
    cout<<ans1+m<<endl<<ans2<<endl;
    return 0;
}