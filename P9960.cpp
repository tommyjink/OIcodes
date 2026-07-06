#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+100;
int n,tot=0,ans=0;
map<string,int> mp;
vector<int> a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        int k;
        cin>>s>>k;
        for(int j=1;j<=k;j++)
        {
            string ss;
            cin>>ss;
            if(!mp[ss])
                mp[ss]=++tot;
            a[i].push_back(mp[ss]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int cnt=0;
            for(int k=0;k<(int)a[i].size();k++)
            {
                for(int q=0;q<(int)a[j].size();q++)
                {
                    if(a[i][k]==a[j][q])
                        cnt++,ans=max(cnt,ans);
                }
            }
        }
    }
    cout<<ans+1<<endl;
    return 0;
}