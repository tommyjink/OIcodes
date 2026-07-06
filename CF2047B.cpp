#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s;
int cnt['z'+10];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        int n,maxn=-1,minn=1e9,ma,mi;
        cin>>n>>s;
        for(int i=1;i<=n;i++)
            cnt[s[i-1]]++;
        for(int i=1;i<=n;i++)
        {
            if(cnt[s[i-1]]>=maxn)
                maxn=cnt[s[i-1]],
                ma=i-1;
            if(cnt[s[i-1]]<minn)
                minn=cnt[s[i-1]],
                mi=i-1;
        }
        if(s[mi]==s[ma])
            for(int i=1;i<=n;i++)
            {
                if(s[i-1]!=s[mi])
                {
                    s[i-1]=s[ma];
                    break;
                }
            }
        else s[mi]=s[ma];
        cout<<s<<endl;
        // cout<<"?"<<s<<endl;
        // cout<<mi<<" "<<ma<<endl;
    }
    return 0;
}