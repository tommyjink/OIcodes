#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<double,double>
using namespace std;
const int N=1e6+10;
int n,m;
double l,vx,vy;
struct node
{
    int first;
    double second;
}a[N];
bool cmp(node x,node y)
{
    return x.first<y.first;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>l>>vx>>vy;
    for(int i=1;i<=n;i++)
    {
        int x;
        double y;
        cin>>x>>y;
        a[i]=(node){x,(y-x)/vx+(l-y)/vy};
    }
    sort(a+1,a+1+n,cmp);
    for(int i=2;i<=n;i++)
        a[i].second=min(a[i].second,a[i-1].second);
    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        int ll=1,rr=n;
        while(ll<rr)
        {
            int mid=(ll+rr+1)>>1;
            if(a[mid].first<=x)ll=mid;
            else rr=mid-1;
        }
        double res=(l-x*1.0)/vy;
        if(a[ll].first<=x)
            res=min(res,a[ll].second);
        printf("%.8lf\n",res);
    }
    return 0;
}
/*

3 3 10 4 1
0 5
2 4
7 9
3
8
5



1 3 100 100 1
1 2
0
1
2

*/