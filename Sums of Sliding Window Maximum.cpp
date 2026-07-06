#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,a[N],l[N],r[N],st[N],top;
int b[N],c[N],ans[N];
void add(int l,int r,int x,int y)
{
    if(l>r)return;
    b[l]+=x,b[r+1]-=x;
    c[l]+=y,c[r+1]-=y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        while(top&&a[st[top]]<=a[i])top--;
        l[i]=i-(top?st[top]:0);
        st[++top]=i;
    }
    top=0;
    for(int i=n;i>=1;i--)
    {
        while(top&&a[st[top]]<a[i])top--;
        r[i]=(top?st[top]:n+1)-i;
        // cout<<r[i]<<" ";
        st[++top]=i;
    }
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        int x=min(l[i],r[i]),y=max(l[i],r[i]),z=l[i]+r[i]-1;
        add(1,x,a[i],0);
        add(x+1,y,0,a[i]*x);
        add(y+1,z,-a[i],a[i]*(l[i]+r[i]));
    }
    for(int i=1;i<=n;i++)b[i]+=b[i-1];
    for(int i=1;i<=n;i++)c[i]+=c[i-1];
    for(int i=1;i<=n;i++)cout<<b[i]*i+c[i]<<endl;
    return 0;
}
