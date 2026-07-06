#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int M=50;
int n,p[M];
void insert(int x)
{
    for(int i=M-1;i>=0;i--)
    {
        if((x>>i) & 1)
        {
            if(!p[i]){p[i]=x;return;}
            else x^=p[i];
        }
    }
}
int query_max()
{
    int res=0;
    for(int i=M-1;i>=0;i--)
        if((res^p[i])>res)
            res^=p[i];
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        insert(x);
    }
    cout<<query_max();
    return 0;
}