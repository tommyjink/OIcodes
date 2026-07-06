#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n,m,c,pre[N];
string s;
vector<pii> ans;
void solve()
{
    cin>>n>>m>>s;
    ans.clear();
    pre[n]=0;
    for(int i=n-1;i>=0;i--)
        pre[i]=pre[i+1]+s[i]-'0';
    if(pre[0]*m%n!=0)
    {
        cout<<-1<<endl;
        return;
    }
    c=pre[0]*m/n;
    for(int i=n-m;i>=0;i--)
    {
        if(pre[i]-pre[i+m]==c)
        {
            ans.push_back((pii){i+1,i+m});
            break;
        }
    }
    if(!ans.empty())
    {
        cout<<1<<endl;
        cout<<ans[0].first<<" "<<ans[0].second<<endl;
        return;
    }
    int sum=0;
    for(int i=0;i<m;i++)
    {
        sum+=s[i]-'0';
        if(sum+pre[n-m+i+1]==c)
        {
            ans.push_back((pii){1,i+1});
            ans.push_back((pii){n-m+i+2,n});
            break;
        }
    }
    cout<<2<<endl;
    cout<<ans[0].first<<" "<<ans[0].second<<endl;
    cout<<ans[1].first<<" "<<ans[1].second<<endl;
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
