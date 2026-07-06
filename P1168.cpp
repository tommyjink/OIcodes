#include<bits/stdc++.h>
#define int long long
#define lowbit(x) x&(-x)
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],tot=0,t[N];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    tot=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(b+1,b+1+n,a[i])-b;
    for(int i=1;i<=n;i++)
    {
        add(a[i],1);
        if(i&1)
        {
            int l=0,r=n,x=(i+1)/2;
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(query(mid)>=x)r=mid-1;
                else l=mid;
            }
            cout<<b[l+1]<<endl;
        }
    }
    return 0;
}