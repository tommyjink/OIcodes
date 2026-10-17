#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int n,x,y,z,m0,m1,c0,c1;
int top;
int num[N];
int val[N],lst,ans;

void push(int x,int y)
{
    // cout<<"push:"<<x<<","<<y<<endl;
    if(!x)return;
    if(top&&val[top]==y)num[top]+=x;
    else
    {
        top++;
        num[top]=x;
        val[top]=y;
    }
}
void solve(int x)
{
    // cout<<"solve:"<<x<<endl;
    int k=x;
    int sum=0,last=0;
    while(k&&top)
    {
        int t=min(k,num[top]);
        sum+=t*val[top];
        last=val[top];
        k-=t;
        num[top]-=t;
        if(!num[top])top--;
    }
    ans+=(x-k)+sum;
    // cout<<"ans+="<<(x-k)+sum<<endl;
    if(k)lst=0;
    else lst=last+1;
}

signed main()
{
    freopen("algorithm.in","r",stdin);
    freopen("algorithm.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>x>>y>>z>>m0>>m1>>c0>>c1;
    for(int i=0;i<n;i++)
    {
        int c;
        if(i==0)c=c0;
        else if(i==1)c=c1;
        else
        {
            int mod=(i%2==0?m0:m1);
            c=(c1*x+c0*y+z)%mod+1;
            c0=c1;
            c1=c;
        }
        // cout<<"i="<<i<<","<<"c="<<c<<endl;
        if(i%2==0)
        {
            push(1,lst);
            push(c-1,0);
            lst=0;
        }
        else solve(c);
    }
    cout<<ans<<endl;
    return 0;
}
