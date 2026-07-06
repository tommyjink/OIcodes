#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
int solve(int *a)
{
    int res=0;
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        q.push(a[i]),q.push(a[i]);
        res+=q.top()-a[i];q.pop();
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],b[n-i+1]=a[i];
    cout<<min(solve(a),solve(b));

    return 0;
}