#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+1000;
int n,a[N],pre[N],ans=1e9;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!pre[a[i]])
        {
            pre[a[i]]=i;
            continue;
        }
        else
        {
            ans=min(ans,i-pre[a[i]]+1);
            pre[a[i]]=i;
        }
    }
    if(ans==1e9)
        cout<<"-1";
    else cout<<ans<<endl;
    return 0;
}