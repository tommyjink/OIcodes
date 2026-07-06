#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],s[N],tot=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    s[++tot]=a[1];
    for(int i=2;i<=n;i++)
        if(a[i]>s[tot]) s[++tot]=a[i];
        else s[lower_bound(s+1,s+1+tot,a[i])-s]=a[i];
    cout<<tot<<endl;
    return 0;
}