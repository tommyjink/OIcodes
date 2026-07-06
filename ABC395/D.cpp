#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+1000;
int n,q,a[N],num[N],f[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        a[i]=num[i]=f[i]=i;
    while(q--)
    {
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int x,y;
            cin>>x>>y;
            a[x]=f[y];
        }
        if(ch==2)
        {
            int x,y;
            cin>>x>>y;
            swap(num[f[x]],num[f[y]]);
            swap(f[x],f[y]);
        }
        if(ch==3)
        {
            int x;
            cin>>x;
            cout<<num[a[x]]<<endl;
        }
    }
    return 0;
}