#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&(-x))
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,q,t[N],t1[N];
void add(int *t,int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]=(t[i]+d)%P;
}
int query(int *t,int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res=(res+t[i])%P;
    return res;
}
int sum(int *t,int l,int r)
{
    if(l<=r)return ((query(t,r)-query(t,l-1))%P+P)%P;
    else return (sum(t,l,n)+sum(t,1,r))%P;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        if(sum(t,x,y)==0&&sum(t1,x,y)==0)
        {
            cout<<"Yes"<<endl;
            add(t,x,i),add(t,y,(-i+P)%P);
            add(t1,x,i*i%P*i%P),add(t1,y,(-i*i%P*i%P+P)%P);
        }
        else cout<<"No"<<endl;
    }
    return 0;
}