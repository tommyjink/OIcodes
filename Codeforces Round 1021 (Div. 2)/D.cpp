#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1005;
int n=0,m=0,k=0;
struct node
{
    int x,y;
};
vector<node> a[N*N];
void solve()
{
    for(int i=1;i<=2*k+1;i++)
        a[i].clear();
    cin>>n>>m>>k;
    for(int i=1;i<=2*k+1;i+=2)
    {
        int x,y;
        cin>>x>>y;
        a[i].push_back((node){x,y});
        if(i==1)continue;
        
    }
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
/*
5
2 4 2
1 1
2 2
2 4
1 4 1
1 1
1 4
5 5 11
2 5
3 4
4 5
5 4
4 3
5 2
4 1
3 2
2 1
1 2
2 3
1 4
3 4 4
1 2
2 1
3 2
2 3
3 4
3 3 2
2 2
1 1
1 3

*/