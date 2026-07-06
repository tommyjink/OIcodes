#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e7+10;
int n,q,a[N],t[N],cnt[N],sum=0;
void add(int x,int d)
{
    for(int i=x;i<N;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    sum=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        add(cnt[a[i]],1);
    }
    while(q--)
    {
        int op,x;
        cin>>op>>x;
        if(op==1)
        {
            cnt[x]++;
            sum++;
            add(cnt[x],1);
        }
        if(op==2)
        {
            cnt[x]--;
            sum--;
            add(cnt[x]+1,-1);
        }
        if(op==3)
        {
            cout<<sum-query(x)<<endl;
        }
    }
    return 0;
}