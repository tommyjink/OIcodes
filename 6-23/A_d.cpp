#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

int n=4,ans=-1,amax=-1;
bool check(int x)
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(x&(1ll<<(i-1)))
        {
            if(q.empty())return false;
            q.pop();
        }
        else q.push(i);
    }
    if(!q.empty())return false;
    return true;
}
void print(int x)
{
    if(x==-1)
    {
        cout<<"NO ANSWER!"<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(x&(1ll<<(i-1)))
            cout<<")";
        else cout<<"(";
    }
    cout<<endl;
}
void solve(int x)
{
    n=x;
    ans=amax=-1;
    cout<<"n="<<n<<endl;
    for(int i=0;i<(1ll<<n);i++)
    {
        if(!check(i))continue;
        int y=0,res=0;
        for(int j=1;j<=n;j++)
            if(i&(1ll<<(j-1)))
                y|=(1ll<<(n-j));
        for(int j=1;j<=n;j++)
            if((i&(1ll<<(j-1)))==(y&(1ll<<(j-1))))
                res++;
        if(res>amax)amax=res,ans=i;
        // print(i);
        // print(y);
        // cout<<endl;
    }
    print(ans);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<=30;i+=2)
        solve(i);
    return 0;
}