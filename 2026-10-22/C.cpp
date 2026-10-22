#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
unordered_map<string,int> f;
int calc(const string &s)
{
    if(f.count(s))return f[s];
    int n=s.size(),ans=n;
    for(int l=0;l<n;l++)
    {
        for(int r=l+1;r<n;r+=2)
        {
            bool ok=true;
            for(int x=l,y=r;x<y;x++,y--)
                if(s[x]!=s[y])
                {
                    ok=false;
                    break;
                }
            if(!ok)continue;
            string t=s.substr(0,l)+"0"+s.substr(r+1);
            ans=min(ans,calc(t));
            if(ans==1)return f[s]=1;
        }
    }
    return f[s]=ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--)
    {
        string s;cin>>s;
        f.clear();
        int ans=0;
        for(int i=1;i<=(int)s.size();i++)
            ans^=i*calc(s.substr(0,i));
        cout<<ans<<endl;
    }
    return 0;
}
