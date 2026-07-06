#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
using u128=__uint128_t;
const int N=40,P=998244353;
int m,d,jj,rb;
int pwm[N],pre[N];
u128 pw[N];
string s;
vector<int> len,high;
vector<vector<int>> nd;
map<pair<int,vector<int>>,u128> mp;
set<pair<int,vector<int>>> bad;
string tos(u128 x)
{
    if(!x)return "0";
    string res;
    while(x)
    {
        res.push_back(x%10+'0');
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
int modu(u128 x)
{
    return x%P;
}
bool check(u128 n,int r)
{
    string t;
    u128 x=n;
    while((int)t.size()<r+(int)s.size())
    {
        t+=tos(x);
        x++;
    }
    for(int i=0;i<(int)s.size();i++)
        if(s[i]!='?'&&s[i]!=t[r+i])return false;
    return true;
}
int posmod(u128 n,int r)
{
    int x=tos(n).size();
    u128 del=n-pw[x-1];
    int res=pre[x-1];
    res=(res+modu(del)*x)%P;
    res=(res+r+1)%P;
    return res;
}
u128 pos(u128 n,int r)
{
    int x=tos(n).size();
    u128 res=0;
    for(int i=1;i<x;i++)
        res+=(u128)9*pw[i-1]*i;
    res+=(n-pw[x-1])*x;
    res+=r+1;
    return res;
}
pair<bool,u128> dfs(int p,vector<int> c)
{
    pair<int,vector<int>> key={p,c};
    if(mp.count(key))return {true,mp[key]};
    if(bad.count(key))return {false,0};
    if(p==d)
    {
        bool ok=true;
        for(int j=0;j<=jj;j++)
        {
            if(j<rb)
            {
                if(c[j])
                {
                    ok=false;
                    break;
                }
            }
            else
            {
                if(!c[j])
                {
                    ok=false;
                    break;
                }
                if(high[j]!=-1&&high[j]!=c[j])
                {
                    ok=false;
                    break;
                }
            }
        }
        if(ok)
        {
            mp[key]=0;
            return {true,0};
        }
        bad.insert(key);
        return {false,0};
    }
    bool flg=false;
    u128 mn=0;
    for(int x=0;x<=9;x++)
    {
        if(p==d-1&&!x)continue;
        vector<int> nxt(jj+1);
        bool ok=true;
        for(int j=0;j<=jj;j++)
        {
            int val=x+c[j],dig=val%10;
            if(nd[j][p]!=-1&&nd[j][p]!=dig)
            {
                ok=false;
                break;
            }
            nxt[j]=val/10;
        }
        if(!ok)continue;
        auto res=dfs(p+1,nxt);
        if(!res.first)continue;
        u128 val=res.second+(u128)x*pw[p];
        if(!flg||val<mn)flg=true,mn=val;
    }
    if(flg)
    {
        mp[key]=mn;
        return {true,mn};
    }
    bad.insert(key);
    return {false,0};
}
void solve()
{
    cin>>s;
    m=s.size();
    bool flg=false;
    u128 best=0;
    int ans=0;
    for(d=1;d<=m+1;d++)
    {
        for(int r=0;r<d;r++)
        {
            for(int b=1;b<=m+2;b++)
            {
                len.clear();
                int sum=0;
                while(sum<r+m)
                {
                    int j=len.size();
                    if(j>m+2)break;
                    int x=d+(j>=b);
                    len.push_back(x);
                    sum+=x;
                }
                if(sum<r+m)continue;
                jj=len.size()-1;
                rb=min(b,jj+1);
                nd.assign(jj+1,vector<int>(d,-1));
                high.assign(jj+1,-1);
                bool ok=true;
                for(int i=0;i<m&&ok;i++)
                {
                    if(s[i]=='?')continue;
                    int g=r+i,cur=0;
                    for(int j=0;j<=jj;j++)
                    {
                        if(g<cur+len[j])
                        {
                            int off=g-cur,v=s[i]-'0';
                            if(len[j]==d)
                            {
                                int p=d-1-off;
                                if(p<0||p>=d)ok=false;
                                else
                                {
                                    if(nd[j][p]!=-1&&nd[j][p]!=v)ok=false;
                                    nd[j][p]=v;
                                }
                            }
                            else
                            {
                                if(!off)
                                {
                                    if(high[j]!=-1&&high[j]!=v)ok=false;
                                    high[j]=v;
                                }
                                else
                                {
                                    int p=d-off;
                                    if(p<0||p>=d)ok=false;
                                    else
                                    {
                                        if(nd[j][p]!=-1&&nd[j][p]!=v)ok=false;
                                        nd[j][p]=v;
                                    }
                                }
                            }
                            break;
                        }
                        cur+=len[j];
                    }
                }
                if(!ok)continue;
                vector<int> c(jj+1);
                for(int j=0;j<=jj;j++)
                    c[j]=j;
                mp.clear();
                bad.clear();
                auto res=dfs(0,c);
                if(!res.first)continue;
                u128 n=res.second;
                if(n<pw[d-1]||n>=pw[d])continue;
                if(!check(n,r))continue;
                u128 p=pos(n,r);
                if(!flg||p<best)
                {
                    flg=true;
                    best=p;
                    ans=posmod(n,r);
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pw[0]=pwm[0]=1;
    for(int i=1;i<N;i++)
    {
        pw[i]=pw[i-1]*10;
        pwm[i]=pwm[i-1]*10%P;
    }
    for(int i=1;i<N;i++)
        pre[i]=(pre[i-1]+9*pwm[i-1]%P*i)%P;
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
