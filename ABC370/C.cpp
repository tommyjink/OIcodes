#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s,t;
int n,ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>t;
    n=s.length();
    s=" "+s;
    t=" "+t;
    for(int i=1;i<=n;i++)
        if(s[i]!=t[i])ans++;
    cout<<ans<<endl;
    for(int i=1;i<=ans;i++)
    {
        int tmp=-1,tmp2=-1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]>t[i]&&tmp==-1)
                tmp=i;
            if(s[i]!=t[i])tmp2=i;
        }
        if(tmp==-1)
            s[tmp2]=t[tmp2];
        else s[tmp]=t[tmp];
        for(int i=1;i<=n;i++)cout<<s[i];
        cout<<endl;
    }
    return 0;
}