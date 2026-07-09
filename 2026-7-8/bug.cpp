#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,INF=4e18;
int n,a[N],ans,step;

int calc(int x)
{
    if(x<=1)return 0;
    return (x-1)/2;
}

int get1(int x)
{
    return calc(x-1)+calc(n-x);
}

int get2(int l,int r)
{
    return (r-l)/2+calc(l-1)+calc(n-r);
}

int A(int x)
{
    return calc(x-1)-x/2;
}

int B(int x)
{
    return x/2+calc(n-x);
}

void upd(int val,int op)
{
    if(val>ans)
    {
        ans=val;
        step=op;
    }
    else if(val==ans&&op<step)step=op;
}
void solve(int p)
{
    int sum=0,cnt=0,l=0,r=0,mx=-INF;
    for(int i=p;i<=n;i+=2)
    {
        if(a[i]>0)
        {
            sum+=a[i];
            cnt++;
            if(!l)l=i;
            r=i;
        }
        if(a[i]>mx)mx=a[i];
    }
    int best=-INF;
    if(sum>0)
    {
        // calcu(sum,0);
        if(cnt==1)best=get1(l);
        int la=-INF,lb=-INF,ra=-INF,rb=-INF;
        for(int i=p;i<=n;i+=2)
        {
            if(a[i]<0)continue;
            if(i<=l&&A(i)>la)la=A(i);
            if(i<l&&A(i)>lb)lb=A(i);
            if(i>=r&&B(i)>ra)ra=B(i);
            if(i>r&&B(i)>rb)rb=B(i);
        }
        if(l<r)best=max(best,la+ra);
        else
        {
            if(lb!=-INF)best=max(best,lb+ra);
            if(rb!=-INF)best=max(best,la+rb);
        }
        upd(sum,n-1-best);
        return;
    }
    int la=-INF;
    bool flag=false;
    for(int i=p;i<=n;i+=2)
    {
        if(a[i]!=0)continue;
        flag=true;
        best=max(best,get1(i));
        if(la!=-INF)best=max(best,la+B(i));
        la=max(la,A(i));
    }
    if(flag)
    {
        upd(0,n-1-best);
        return;
    }
    for(int i=p;i<=n;i+=2)
        if(a[i]==mx)best=max(best,get1(i));
    upd(mx,n-1-best);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bug.in","r",stdin);
    freopen("bug.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ans=-INF,step=INF;
    solve(1);
    if(n>=2)solve(2);
    cout<<ans<<endl<<step<<endl;
    return 0;
}
