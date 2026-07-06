#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int a[N],b[N],c[N];
char s[N];
void solve()
{
    int n,r=0,mid=0,cnt=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=c[i]=0,s[i]=' ';
    for(int i=1;i<=n;i++)
    {
        if(i<=r)b[i]=min(b[mid*2-i],r-i+1);
        else cnt=(cnt+1)%26,s[i]='a'+cnt;
        while(b[i]<a[i]&&i+b[i]<=n&&i-b[i]>=1)s[i+b[i]]=s[i-b[i]],b[i]++;
        if(i+b[i]-1>r)r=i+b[i]-1,mid=i;
    }
    r=0,mid=0;
    for(int i=1;i<=n;i++)
    {
        if(i<=r)c[i]=min(c[mid*2-i],r-i+1);
        while(s[i-c[i]]==s[i+c[i]]&&i-c[i]>=1&&i+c[i]<=n)c[i]++;
        if(i+c[i]-1>=r)r=i+c[i]-1,mid=i;
    }
    for(int i=1;i<=n;i++)
        if(a[i]!=c[i]){cout<<"No"<<endl;return;}
    cout<<"Yes"<<endl;
    return;
    for(int i=1;i<=n;i++)
        cout<<s[i];
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}