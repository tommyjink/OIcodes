#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k;
struct node
{
    int a,b;
}a[N];
bool cmp(node x,node y)
{
    return x.a<y.a;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].a>>a[i].b;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        a[i].b+=+a[i-1].b;
    for(int i=1;i<=n;i++)
        if(a[i].a*k<a[i].b)
        {
            cout<<"No"<<endl;
            return;
        }
    cout<<"Yes"<<endl;
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