#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int l,r,x;
            cin>>l>>r>>x;
            for(int i=l;i<=r;i++)a[i]&=x;
        }
        else if(op==2)
        {
            
        }
        else
        {

        }
    }
    return 0;
}