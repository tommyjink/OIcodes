#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=2005;
int n,a[N],siz[N],vis[N],best;
vector<int> g[N];

void fail(string s,int code)
{
    cout<<s<<endl;
    exit(code);
}

void dfs(int x)
{
    siz[x]=(x!=1&&x!=n);
    bitset<N> f;
    f[0]=1;
    int sum=0,res=0;
    for(int v:g[x])
    {
        dfs(v);
        sum+=siz[v];
        f|=f<<siz[v];
    }
    for(int i=0;i<=sum;i++)
        if(f[i])res=max(res,i*(sum-i));
    best+=res;
    siz[x]+=sum;
}

pii calc(int x,int k)
{
    int l=0,r=0;
    if(x!=1&&x!=n)
    {
        l=(a[x]<a[k]);
        r=(a[x]>a[k]);
    }
    for(int v:g[x])
    {
        pii t=calc(v,k);
        l+=t.first,r+=t.second;
    }
    return {l,r};
}

int query()
{
    int ans=0;
    for(int x=1;x<=n;x++)
    {
        int l=0,r=0;
        for(int v:g[x])
        {
            pii t=calc(v,x);
            ans+=l*t.second+r*t.first;
            l+=t.first,r+=t.second;
        }
    }
    return ans;
}

void read(ifstream &in,int code,string name)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!(in>>a[i]))fail(name+": missing or invalid L["+to_string(i)+"]",code);
        if(a[i]<1||a[i]>n)fail(name+": L["+to_string(i)+"]="+to_string(a[i])+" is out of range",code);
        if(vis[a[i]]++)fail(name+": repeated label "+to_string(a[i]),code);
    }
    string s;
    if(in>>s)fail(name+": extra output",code);
}

signed main(signed argc,char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(argc!=3&&argc!=4)
        fail("Usage: C_checker input output [answer]",2);
    ifstream in(argv[1]),out(argv[2]);
    if(!in||!out)fail("Cannot open input or output",2);
    if(!(in>>n)||n<2||n>2000)fail("Invalid n",2);
    int p[N]={};
    for(int i=2;i<=n;i++)
    {
        if(!(in>>p[i])||p[i]<1||p[i]>n||p[i]==i)fail("Invalid parent",2);
        g[p[i]].push_back(i);
    }
    // Each non-root vertex has exactly one parent; reachability rules out cycles.
    vector<int> q={1};
    for(int i=0;i<(int)q.size();i++)
        for(int v:g[q[i]])q.push_back(v);
    if((int)q.size()!=n)fail("Input is not a rooted tree",2);
    dfs(1);
    read(out,1,"WA");
    int ans=query();
    if(argc==4)
    {
        ifstream ref(argv[3]);
        if(!ref)fail("Cannot open answer",2);
        read(ref,2,"Invalid answer");
        int val=query();
        if(val!=best)fail("Answer is suboptimal: score="+to_string(val)+", optimum="+to_string(best),2);
    }
    if(ans!=best)fail("WA: score="+to_string(ans)+", optimum="+to_string(best),1);
    cout<<"OK: score="<<ans<<", optimum="<<best<<endl;
    return 0;
}
