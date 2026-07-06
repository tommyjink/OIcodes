#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],c[N],x[N];
struct node
{
    int val,num;
};
bool operator <(node x,node y)
{
    return x.val>y.val;
}
int f(int i,int x)
{
    return a[i]*x*x+b[i]*x+c[i];
}
priority_queue<node> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++)
        q.push((node){f(i,++x[i]),i});
    for(int i=1;i<=m;i++)
    {
        node t=q.top();q.pop();
        cout<<t.val<<" ";
        q.push((node){f(t.num,++x[t.num]),t.num});
    }
    return 0;
}