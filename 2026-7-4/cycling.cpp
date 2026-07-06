#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int T,n,a[N],p[N],ans[N],mx;
string s,best;

string work(string t,int x)
{
    string res="";
    int len=t.size();
    for(int i=0;i<x;i++)
        res+=t[i%len];
    return res;
}

string calc()
{
    string now=s;
    for(int i=1;i<=n;i++)
        now=work(now,a[p[i]]);
    return now;
}

void solve()
{
    cin>>s>>n;
    mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        p[i]=ans[i]=i;
        if(a[i]>mx)mx=a[i];
    }
    if(n<=8&&mx<=200000)
    {
        best="";
        do
        {
            string now=calc();
            if(best==""||now>best)
            {
                best=now;
                for(int i=1;i<=n;i++)
                    ans[i]=p[i];
            }
        }while(next_permutation(p+1,p+n+1));
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cycling.in","r",stdin);
    freopen("cycling.out","w",stdout);
    cin>>T;
    while(T--)solve();
    return 0;
}
