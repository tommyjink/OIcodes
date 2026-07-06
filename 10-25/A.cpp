#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
#define c(x,y) (m*(x-1)+y)
using namespace std;
const int N=5e5+10;
int n,m,q,a[N],b[N];
map<pii,int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(b,127,sizeof(b));
    cin>>m>>n>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[c(i,j)];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[c(i,j)]+=a[c(i,j-1)];
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        if(mp.count(pii(l,r)))
            cout<<mp[pii(l,r)]<<endl;
        else
        {
            int res=0;
            for(int i=1;i<=n;i++)
                res=max(res,a[c(i,r)]-a[c(i,l-1)]);
            mp[pii(l,r)]=res;
            cout<<res<<endl;
        }
    
    }
    return 0;
}
/*
7 2 3
1 1 4 5 1 4 0
1 9 1 9 8 1 0
6 7
5 7
1 3


4
9
11

*/