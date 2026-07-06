#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,vis[N],ans=0;
struct node
{       
    int x,y;
}a[N];  
bool cmp(node x,node y)
{       
    return x.x==y.x?x.y>y.y:x.x>y.x;
}
signed main()
{       
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int p=a[i].y;
        while(vis[p])
            p--;
        if(p==0)continue;
        vis[p]=true;
        ans+=a[i].x;
    }
    cout<<ans<<endl;
    return 0;
}