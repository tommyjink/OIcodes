#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n; 
struct node
{
    int v,num;
}a[N];
bool cmp(node x,node y)
{
    return x.v<y.v;
}
int gcd(int x,int y)
{
    if(x<y)swap(x,y);
    return y==0?x:gcd(y,x%y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].v,a[i].num=i;
    sort(a+1,a+1+n,cmp);
    int res=abs(a[1].num-1);
    for(int i=1;i<=n;i++)
        if(abs(a[i].num-i))res=gcd(res,abs(a[i].num-i));
    int ans=0;
    for(int i=1;i<=res;i++)
        if(res%i==0)ans++;
    if(res==0)cout<<n<<endl;
    else cout<<ans<<endl;
    return 0;
}