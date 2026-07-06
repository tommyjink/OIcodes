#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,p=0,ans=0;
struct node
{
    int x,y;
}a[N];
bool cmp(node x,node y)
{
    return x.x<y.x;
}
priority_queue<int,vector<int>,greater<int>> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        while(p==a[i].x&&!q.empty()&&q.top()<a[i].y)
            ans-=q.top(),q.pop(),p--;
        if(p==a[i].x)continue;
        p++,ans+=a[i].y,q.push(a[i].y);
    }
    cout<<ans<<endl;
    return 0;
}