#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e6+10;
int n,l[N],r[N],ans=0;
bool ok(int L,int R)
{
    int cur=l[L];
    for(int i=L+1;i<R;i++)
    {
        if(cur<l[i]||cur>r[i])return true;
        cur=l[i]+r[i]-cur;
    }
    return cur!=l[R];
}
int cal(int L,int R)
{
    if(L>R||L<1||R>n)return 0;
    // cout<<L<<","<<R<<endl;
    int p=L,res=0;
    while(p<=R&&r[p]>l[p])p++,res++;
    if(p>R)return R-L+1;
    int x=p,cntx=0;
    while(p<=R&&l[p]==r[p])p++,cntx++;
    // cout<<p<<"!"<<cntx<<endl;
    while(1)
    {
        if(p>R)return res+cntx*cntx;
        // cout<<"!"<<endl;
        int y=p,cnty=0;
        while(p<=R&&r[p]>l[p])p++,cnty++;
        if(p>R)return res+cntx*cntx+cnty;
        int z=p,cntz=0;
        while(p<=R&&l[p]==r[p])p++,cntz++;
        bool tmp=ok(y-1,z);
        // cout<<x<<","<<y<<","<<z<<","<<tmp<<endl;
        if(tmp)res+=cntx*cntx+cnty;
        else if(cnty==1&&cntx<=cntz)res+=(cntx+1)*(cntx+1);
        else if(cnty==1)res+=cntx*cntx,cntz++;
        else res+=cntx*cntx+cnty+2;
        cntx=cntz,x=z;
    }
}
void solve()
{
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>l[i];
    for(int i=1;i<=n;i++)cin>>r[i];
    int lst=1;
    for(int i=1;i<=n;i++)
    {
        if(r[i]-l[i]>1)ans+=cal(lst,i-1)+1,lst=i+1;
        else if(l[i]>r[i-1]||r[i]<l[i-1])ans+=cal(lst,i-1),lst=i;
    }
    // cout<<cal(2,3)<<"::"<<endl;
    ans+=cal(lst,n);
    cout<<ans<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}