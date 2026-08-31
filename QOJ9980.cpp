#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=(1<<15)+10;
int n,a[N],vis[N];
vector<string> v;

string dfs(char now,vector<string> v)
{
    string res;
    vector<string> v1,v2;

    if(v.empty())return res;

    if(v.size()==1)
    {
        if(v[0].empty())return "T";

        for(int i=1;i<v[0].size();i++)res.push_back('(');
        res.push_back(v[0][0]);

        for(int i=1;i<v[0].size();i++)
            res=res+"&"+v[0][i]+")";

        return res;
    }

    for(string s:v)
    {
        if(s.empty())continue;

        if(s[0]==now)v1.push_back(s.substr(1));
        else v2.push_back(s);
    }

    string res1=dfs(now+1,v1);
    string res2=dfs(now+1,v2);

    string L;

    if(!res1.empty())
    {
        if(res1=="T")
        {
            L.push_back(now);
        }
        else
        {
            L+="(";
            L+=now;
            L+="&";
            L+=res1;
            L+=")";
        }
    }

    if(!L.empty()&&!res2.empty())
    {
        res+="(";
        res+=L;
        res+="|";
        res+=res2;
        res+=")";
        return res;
    }
    else if(!L.empty())
    {
        return L;
    }
    else
    {
        return res2;
    }
}

void solve()
{
    string s;
    cin>>n>>s;

    v.clear();

    for(int i=0;i<(1ll<<n);i++)
        a[i]=s[i]-'0',vis[i]=0;

    for(int i=0;i<(1ll<<n);i++)
        for(int j=0;j<n;j++)
            if((i&(1ll<<j))&&a[i^(1ll<<j)]>a[i])
            {
                cout<<"No"<<endl;
                return;
            }

    if(a[0])
    {
        cout<<"Yes"<<endl;
        cout<<"T"<<endl;
        return;
    }

    for(int i=1;i<(1ll<<n);i++)
    {
        for(int j=0;j<n;j++)
            if((i&(1ll<<j))&&vis[i^(1ll<<j)])
                vis[i]=true;

        if(vis[i])continue;

        if(a[i])
        {
            vis[i]=true;

            string t;

            for(int j=0;j<n;j++)
                if(i&(1ll<<j))
                    t.push_back('a'+j);

            v.push_back(t);
        }
    }

    cout<<"Yes"<<endl;

    if(v.empty())
        cout<<"F"<<endl;
    else
        cout<<dfs('a',v)<<endl;
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