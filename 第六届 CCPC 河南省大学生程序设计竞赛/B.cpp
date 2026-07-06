#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,tot=0,now=0,ans=0;
struct node
{
    int num,val;
}c[N];
bool cmp(node x,node y)
{
    return x.val==y.val?x.num>y.num:x.val<y.val;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i].val,c[i].num=i;
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(c[i].num<now)continue;
        tot+=c[i].num-now;
        now=c[i].num;
        ans+=tot/c[i].val;
        tot%=c[i].val;
    }
    cout<<ans<<endl;
    return 0;
}
/*
6
3 2 5 3 4 3

5
6 3 3 4 2

5
7 6 5 9 8
*/