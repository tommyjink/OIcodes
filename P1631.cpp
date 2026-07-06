#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N],b[N],x[N];
struct node
{
    int val,num;
};
bool operator<(node x,node y)
{
    return x.val>y.val;
}
priority_queue<node> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
        q.push((node){a[i]+b[++x[i]],i});
    for(int i=1;i<=n;i++)
    {
        node t=q.top();q.pop();
        cout<<t.val<<" ";
        q.push((node){a[t.num]+b[++x[t.num]],t.num});
    }
    return 0;
}