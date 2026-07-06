#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
int n,cnt[3];
string s;
void solve()
{
    cin>>n>>s;
    int sum=n*(n+1)/2;
    cnt[0]=1;
    cnt[1]=cnt[2]=0;
    int pre=0,z=0;
    for(auto c:s)
    {
        int w=(c=='0'?1:2);
        pre=(pre+w)%3;
        z+=cnt[pre];
        cnt[pre]++;
    }
    int ans=sum-z,res=0;
    for(int i=0;i<n;)
    {
        int j=i;
        while(j+1<n&&s[j]!=s[j+1])
            j++;
        int len=j-i+1;
        res+=(len-1)*(len-1)/4;
        i=j+1;
    }
    cout<<ans-res<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
/*

2 5 1 3 4
3 1 4 5 2

*/