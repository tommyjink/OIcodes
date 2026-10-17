#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
bool check(int x,int d)
{
    int o=a[x];
    a[x]=d;
    for(int i=0;i<=n;i++)b[i]=0;
    stack<int> s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[s.top()]<a[i])s.pop();
        if(!s.empty()&&a[s.top()]==a[i])
            b[s.top()]++,b[i+1]--;
        s.push(i);
    }
    a[x]=o;
    for(int i=2;i<=n;i++)
        b[i]+=b[i-1];
    for(int i=1;i<=n;i++)
        if(b[i]==0)return false;
    if(x==0)return true;
    cout<<"1"<<endl;
    cout<<x<<" "<<d<<endl;
    return true;
}
void solve()
{
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],mx=max(mx,a[i]);
    int p1=0,p2=1;
    for(int i=1;i<=n;i++)
    {
        if(!p1&&a[i]==mx)p1=i;
        if(a[i]==mx)p2=i;
    }
    if(check(0,0))cout<<"0"<<endl;
    else
    {
        if(check(1,mx)||check(n,mx)||check(p1,1)||check(p2,1))return;
        cout<<"2"<<endl;
        cout<<"1 "<<mx<<endl;
        cout<<n<<" "<<mx<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}