#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,a[N],pos[N];
signed main()
{
    freopen("shelf.in","r",stdin);freopen("shelf.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],pos[a[i]]=i;
    int x=1;
    while(x<n&&pos[x]<pos[x+1])x++;
    cout<<n-x<<endl;
    return 0;
}
