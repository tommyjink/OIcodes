#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,r,c,sum1=0,sum2=0;
string s;
map<pair<int,int>,int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>r>>c>>s;
    s=" "+s;
    mp[make_pair(0,0)]=true;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='N')
            sum1--;
        if(s[i]=='W')
            sum2--;
        if(s[i]=='S')
            sum1++;
        if(s[i]=='E')
            sum2++;
        mp[make_pair(sum1,sum2)]=true;
        if(mp.count(make_pair(sum1-r,sum2-c)))
            cout<<"1";
        else cout<<"0";
    }
    return 0;
}