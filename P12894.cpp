#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=1e6+10;
int n,m,a[N];
int t1[N],t2[N];
void add(int *t,int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int *t,int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
int cal(int len,int cnt1,int cnt2)
{
    return (len*len-len+(2*len-1)*cnt1-cnt1*cnt1+2*cnt1*cnt2)/2;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)add(t1,i,1);
        if(a[i]==2)add(t2,i,1);
    }
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
        {
            int len=y-x+1;
            int cnt1=query(t1,y)-query(t1,x-1);
            int cnt2=query(t2,y)-query(t2,x-1);
            cout<<cal(len,cnt1,cnt2)<<endl;
        }
        else
        {
            if(a[x]==1)add(t1,x,-1);
            if(a[x]==2)add(t2,x,-1);
            if(y==1)add(t1,x,1);
            if(y==2)add(t2,x,1);
            a[x]=y;
        }
    }
    return 0;
}