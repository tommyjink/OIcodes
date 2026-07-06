#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10,P=998244353;
int n,m,a[N],t[N],tk[N],d[N],l[N],r[N],ans[N],sum;
struct node
{
    int k,id;
}q[N];
bool cmp(node x,node y)
{
    return x.k<y.k;
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
int lb(int k)
{
    int L=0,R=m;
    while(L<R)
    {
        int mid=(L+R+1)>>1;
        if(q[mid].k<=k)L=mid;
        else R=mid-1;
    }
    return L;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>q[i].k;
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    stack<int>s;
    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[s.top()]>=a[i])s.pop();
        if(!s.empty())l[i]=s.top()+1;
        else l[i]=1;
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=n;i>=1;i--)
    {
        while(!s.empty()&&a[s.top()]>a[i])s.pop();
        if(!s.empty())r[i]=s.top()-1;
        else r[i]=n;
        s.push(i);
    }
    for(int i=1;i<=n;i++)
    {
        int iv=qpow(a[i],P-2),cnt=(i-l[i]+1)%P*(r[i]-i+1)%P;
        sum=(sum+iv*(i%P)%P*((n-i+1)%P)%P)%P;
        int p=lb(a[i]-1),w=((2-a[i]-iv)%P+P)%P;
        t[p]=(t[p]+iv*cnt%P)%P;
        tk[p+1]=(tk[p+1]+cnt)%P;
        d[p+1]=(d[p+1]+w*cnt%P)%P;
    }
    for(int i=m;i>=1;i--)
        t[i]=(t[i]+t[i+1])%P;
    for(int i=1;i<=m;i++)
    {
        tk[i]=(tk[i-1]+tk[i])%P;
        d[i]=(d[i-1]+d[i])%P;
        ans[q[i].id]=((sum+t[i]*q[i].k%P+tk[i]*q[i].k%P+d[i])%P+P)%P;
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}
