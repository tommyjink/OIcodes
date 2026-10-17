#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,s[N],t[N],c[N],len=0;
int ans[N];
struct node
{
    int a,b;
}h[N];
bool operator <(node x,node y)
{
    if(x.a==y.a)return x.b<y.b;
    return x.a<y.a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i]>>t[i];
    for(int i=1;i<=n;i++)
        h[i]={t[i]-s[i],t[i]+s[i]};
    sort(h+1,h+1+n);
    reverse(h+1,h+1+n);
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(c+1,c+1+len,h[i].b)-c;
        if(p==len+1)c[++len]=h[i].b;
        else c[p]=h[i].b;
        ans[i]=p;
    }
    cout<<len<<endl;
    for(int i=1;i<=n;i++)
        cout<<(h[i].b-h[i].a)/2<<" "<<(h[i].a+h[i].b)/2<<" "<<ans[i]<<endl;
    return 0;
}