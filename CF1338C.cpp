#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int cal(int l,int r,int x,int mode)
{
    if(x<=0||x>(r-l+1))return 0;
    if(l==r)return l;
    int len=(r-l+1)/4,res=0;
    if(mode)
    {
        res+=cal(l,l+len-1,x,mode);
        res+=cal(l+len*2,l+len*3-1,x-len,mode);
        res+=cal(l+len*3,l+len*4-1,x-len*2,mode);
        res+=cal(l+len,l+len*2-1,x-len*3,mode);
    }
    else
    {
        res+=cal(l,l+len-1,x,mode);
        res+=cal(l+len*3,l+len*4-1,x-len,mode);
        res+=cal(l+len,l+len*2-1,x-len*2,mode);
        res+=cal(l+len*2,l+len*3-1,x-len*3,mode);
    }
    return res;
}
void solve()
{
    int n,l,r,mode;
    cin>>n;
    int p=0,nn=(n+2)/3;
    while(nn-(1ll<<p)>0)
        nn-=(1ll<<p),p+=2;
    if(n%3==1)
    {
        cout<<(1ll<<p)+nn-1<<endl;
        return;
    }
    else if(n%3==2) l=(1ll<<p)*2,r=(1ll<<p)*3-1,mode=1;
    else l=(1ll<<p)*3,r=(1ll<<p)*4-1,mode=0;
    cout<<cal(l,r,nn,mode)<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}