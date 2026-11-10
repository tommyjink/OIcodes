#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5005;
int n,a[N],ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int r=n;r>=1;r--)
    {
        int cnt=0,res=0,val=0;
        val^=a[r];
        res=1;
        ans+=res;
        for(int l=r-1;l>=1;l--)
        {
            int x=a[l];
            if(x>val)res=1,cnt=0;
            else if(x==1)res++,cnt=1-cnt;
            else res+=2-cnt,cnt=0;
            ans+=res;
            val^=a[l];
        }
    }
    cout<<ans<<endl;
    return 0;
}