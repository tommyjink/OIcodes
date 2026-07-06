#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+100;
int n,m;
map<string,int> mp,mp1[N],mp2;
string f(string s,int x,int y)
{
    return s.substr(x,y-x+1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        mp[s]=true;
        for(int j=0;j<s.length();j++)
        {
            string t=s;
            t.erase(j,1);
            if(!mp1[j].count(t))
                mp1[j][t]=0;
            mp1[j][t]++;
            if(s[j]!=s[j+1])
            {
                if(!mp2.count(t))
                    mp2[t]=0;
                mp2[t]++;
            }
        }
    }
    while(m--)
    {
        string s;
        cin>>s;
        int ans=0;
        if(mp[s])
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=0;i<s.length();i++)
        {
            string t=s;
            t.erase(i,1);
            ans+=mp1[i][t];
            if(s[i]!=s[i+1])
                ans+=mp[t];
            // cout<<t<<" "<<mp1[i][t]<<endl;
        }
        ans+=mp2[s];
        cout<<ans<<endl;
    }
    return 0;
}
/*
4 1
abcd
abcde
aabc
abced

abc

3 1
aa
aac
aaaa

aaa
*/