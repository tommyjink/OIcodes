#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
#define puu pair<ull,ull>
#define endl "\n"
#define lowbit(x) ((x)&(-x))
#define pii pair<int,int>
using namespace std;
const int N=2e6+10;
int n,q,c1=0,ans[N];
struct node
{
    int num;
    string typ;
    string a,c;
    puu h;
    pii p1,p2;
};
vector<node> ops;  
vector<pii> V[N],U[N],Q[N];
vector<int> X,Y;
struct Tree
{
    int t[N];
    void add(int x,int d)
    {
        for(int i=x;i<Y.size()+2;i+=lowbit(i))
            t[i]+=d;
    }
    int query(int x)
    {
        int res=0;
        for(int i=x;i;i-=lowbit(i))
            res+=t[i];
        return res;
    }
    void init(int n)
    {
        for(int i=0;i<=n;i++)
            t[i]=0;
    }
}T;
struct trie
{
    int nex[N][30],cnt=0,dfn[N],odfn[N],now=0;
    void insert(string s)
    {
        int len=s.length(),p=0;
        for(int i=0;i<len;i++)
        {
            int c=s[i]-'a';
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
        }
    }
    void init()
    {
        for(int i=0;i<=cnt;i++)
        {
            dfn[i]=odfn[i]=0;
            for(int j=0;j<=26;j++)
                nex[i][j]=0;
        }
        cnt=now=0;
    }
    void dfs(int x)
    {
        dfn[x]=++now;
        for(int i=0;i<='z'-'a';i++)
            if(nex[x][i])dfs(nex[x][i]);
        odfn[x]=now;
    }
    pii getlr(string s)
    {
        int len=s.length(),p=0;
        for(int i=0;i<len;i++)
        {
            if(nex[p][s[i]-'a'])
                p=nex[p][s[i]-'a'];
            else break;
        }
        return pii(dfn[p],odfn[p]);
    }
}t1,t2;

bool cmp(const node& x, const node& y)
{
    return x.h < y.h;
}
void calx(pii &x)
{
    x.first=lower_bound(X.begin(),X.end(),x.first)-X.begin()+1;
    x.second=lower_bound(X.begin(),X.end(),x.second)-X.begin()+1;
}
void caly(pii &y)
{
    y.first=lower_bound(Y.begin(),Y.end(),y.first)-Y.begin()+1;
    y.second=lower_bound(Y.begin(),Y.end(),y.second)-Y.begin()+1;
}
puu f(string s)
{
    ull res1=0,res2=0,base1=13331,base2=998244353;
    for(int i=0;i<s.length();i++)
        res1=res1*base1+s[i],
        res2=res2*base2+s[i];
    return puu(res1,res2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    ops.reserve(n+q);  
    for(int i=1;i<=n;i++)
    {
        int l=-1,r=-1;
        string s1,s2;
        cin>>s1>>s2;
        if(s1==s2)continue;
        for(int j=0;j<s1.length();j++)
        {
            if(s1[j]!=s2[j]&&l<0)l=j;
            if(s1[j]!=s2[j])r=j;
        }
        node tmp;
        tmp.num=c1+1;
        tmp.typ="op";
        tmp.a=s1.substr(0,l);
        tmp.c=s1.substr(r+1);
        tmp.h=f(s1.substr(l,(r-l+1))+s2.substr(l,(r-l+1)));
        reverse(tmp.a.begin(),tmp.a.end());
        ops.push_back(tmp);
        c1++;
    }
    for(int i=1;i<=q;i++)
    {
        int l=-1,r=-1;
        string s1,s2;
        cin>>s1>>s2;
        if(s1.length()!=s2.length())continue;
        for(int j=0;j<s1.length();j++)
        {
            if(s1[j]!=s2[j]&&l<0)l=j;
            if(s1[j]!=s2[j])r=j;
        }
        node tmp;
        tmp.num=i;
        tmp.typ="query";
        tmp.a=s1.substr(0,l);
        tmp.c=s1.substr(r+1);
        tmp.h=f(s1.substr(l,(r-l+1))+s2.substr(l,(r-l+1)));
        reverse(tmp.a.begin(),tmp.a.end());
        ops.push_back(tmp);
        c1++;
    }
    
    sort(ops.begin(),ops.end(),cmp);
    int p=0;  
    while(p<ops.size())
    {
        t1.init(),t2.init();
        int pp=p;
        while(pp<ops.size()&&ops[pp].h==ops[p].h)pp++;
        pp--;
        for(int i=p;i<=pp;i++)
            if(ops[i].typ=="op")
                t1.insert(ops[i].a),t2.insert(ops[i].c);
        t1.dfs(0),t2.dfs(0);
        X.clear(),Y.clear();
        for(int i=p;i<=pp;i++)
        {
            ops[i].p1=t1.getlr(ops[i].a);
            ops[i].p2=t2.getlr(ops[i].c);
            X.push_back(ops[i].p1.first);
            Y.push_back(ops[i].p2.first);
            X.push_back(ops[i].p1.second);
            Y.push_back(ops[i].p2.second);
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        for(int i=0;i<=X.size();i++)
            V[i].clear(),U[i].clear(),Q[i].clear();
        for(int i=p;i<=pp;i++)
        {
            calx(ops[i].p1),caly(ops[i].p2);
            if(ops[i].typ=="op")
            {
                int x=ops[i].p1.first;
                int xx=ops[i].p1.second;
                int y=ops[i].p2.first;
                int yy=ops[i].p2.second;
                V[x].push_back(pii(y,yy));
                U[xx+1].push_back(pii(y,yy));
            }
            else
            {
                int x=ops[i].p1.first;
                int y=ops[i].p2.first;
                Q[x].push_back(pii(ops[i].num,y));
            }
        }
        
        unordered_set<int> valid_x;
        for(int i=p;i<=pp;i++)
        {
            if(ops[i].typ=="op")
            {
                valid_x.insert(ops[i].p1.first);
                valid_x.insert(ops[i].p1.second+1);
            }
            else
            {
                valid_x.insert(ops[i].p1.first);
            }
        }
        vector<int> xs(valid_x.begin(),valid_x.end());
        sort(xs.begin(),xs.end());
        T.init(Y.size()+10);
        for(int x:xs)
        {
            for(auto j:V[x])
                T.add(j.first,1),T.add(j.second+1,-1);
            for(auto j:U[x])
                T.add(j.first,-1),T.add(j.second+1,1);
            for(auto j:Q[x])
                ans[j.first]=T.query(j.second);
        }
        p=pp+1;
    }
    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
    return 0;
}