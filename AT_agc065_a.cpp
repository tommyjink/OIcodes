#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10,INF=4e18;
int n,k,cnt,mx;
int a[N];
struct node
{
    int x,num;
}p[N];
int calc(int lim)
{
    int res=-INF,pos=0;
    set<int> s;
    for(int i=1;i<=cnt;i++)
        if(p[i].num>=lim)s.insert(p[i].x);
    for(int i=cnt;i>=1;i--)
    {
        if(pos<lim)
        {
            if(!s.empty())res=max(res,*s.begin()-p[i].x);
            else res=max(res,p[cnt].x-p[i].x);
            // cout<<pos<<"!"<<lim<<endl;
        }
        if(p[i].num>=lim-1)s.insert(p[i].x);
        pos=max(pos,p[i].num);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(cnt&&p[cnt].x==a[i])p[cnt].num++;
        else p[++cnt]=(node){a[i],1};
    }
    for(int i=1;i<=cnt;i++)
        mx=max(mx,p[i].num);
    cout<<max(calc(mx)+(n-mx)*k,calc(mx+1)+(n-mx-1)*k)<<endl;
    return 0;
}
