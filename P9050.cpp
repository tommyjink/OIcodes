#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,sum[N],ans[N],b[N];
struct node
{
    int num,val;
}a[N];
bool cmp(node x,node y)
{
    return x.val<y.val;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        a[i].num=i,cin>>a[i].val;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i].val;
        if(i==1)b[i]=true;
        else if(a[i].val==a[i-1].val&&b[i-1])
            b[i]=true;
    }
    if(!b[n])ans[a[n].num]=true;
    for(int i=n-1;i>=1;i--)
        if((!b[i])&&sum[i]>a[i+1].val&&ans[a[i+1].num])
            ans[a[i].num]=true;
    for(int i=1;i<=n;i++)
        if(ans[i])cout<<"T";
        else cout<<"N";
    return 0;
}