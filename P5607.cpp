#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef unsigned long long ull;

struct FastIO
{
    static const int S=1<<20;
    int wpos,rpos,len;
    char wbuf[S],rbuf[S];
    FastIO():wpos(0),rpos(0),len(0){}
    char gc()
    {
        if(rpos==len){rpos=0,len=fread(rbuf,1,S,stdin);if(!len)return 0;}
        return rbuf[rpos++];
    }
    int read()
    {
        int x=0;char c=gc();
        while(c<'0'||c>'9')c=gc();
        while(c>='0'&&c<='9')x=x*10+c-'0',c=gc();
        return x;
    }
    ~FastIO(){if(wpos)fwrite(wbuf,1,wpos,stdout);}
    void pc(char c){if(wpos==S){fwrite(wbuf,1,S,stdout),wpos=0;}wbuf[wpos++]=c;}
    void print(int x)
    {
        if(x==0){pc('0'),pc('\n');return;}
        char s[20];int n=0;
        while(x)s[n++]='0'+x%10,x/=10;
        while(n--)pc(s[n]);
        pc('\n');
    }
}io;

const int M=1e6+10,B=700,K=20;
int m;
int cv[M],bi[M],bc,sz[M],st[M],W;
vector<ull> pool;
vector<int> pos[M];
unordered_map<int,int> it;
int cnt[M],s1[M],s2[M];

void setbit(int id,int b){int p=(id-1)*W;pool[p+(b>>6)]|=1ULL<<(b&63);}
bool getbit(int id,int b){int p=(id-1)*W;return(pool[p+(b>>6)]>>(b&63))&1ULL;}

void addbig(int s,int big)
{
    if(!st[s])st[s]=-big;
    else if(st[s]<0)
    {
        int o=-st[s];
        bc++;
        pool.resize(1LL*bc*W,0);
        st[s]=bc;
        setbit(bc,o),setbit(bc,big);
    }
    else setbit(st[s],big);
}

int countbig(int a,int b)
{
    int A=st[a],B=st[b];
    if(!A||!B)return 0;
    if(A<0&&B<0)return A==B;
    if(A<0&&B>0)return getbit(B,-A);
    if(A>0&&B<0)return getbit(A,-B);
    int pa=(A-1)*W,pb=(B-1)*W,r=0;
    for(int i=0;i<W;i++)r+=__builtin_popcountll(pool[pa+i]&pool[pb+i]);
    return r;
}

int mk(int a,int b){return a*m+b;}

signed main()
{
    m=io.read();
    for(int i=1;i<=m;i++)
    {
        int op=io.read(),x=io.read(),y=io.read();
        if(op==1)cv[y]++;
        else{if(x>y)swap(x,y);if(x!=y)it[mk(x,y)]=0;}
    }
    for(int v=1;v<=m;v++)if(cv[v]>B)bi[v]=++bc;
    W=(bc+63)>>6;
    for(int v=1;v<=m;v++)if(cv[v]>0&&!bi[v])pos[v].reserve(cv[v]);
    it.reserve(m*2);
    bc=0;
    memset(st,0,sizeof(st));
    pool.clear();
    for(int i=1;i<=m;i++)
    {
        int op=io.read(),x=io.read(),y=io.read();
        if(op==1)
        {
            sz[x]++;
            if(bi[y])addbig(x,bi[y]);
            else
            {
                for(int s:pos[y])
                {
                    int a=s,b=x;
                    if(a>b)swap(a,b);
                    it[mk(a,b)]++;
                }
                pos[y].push_back(x);
            }
        }
        else
        {
            int a=x,b=y,cmn;
            if(a>b)swap(a,b);
            if(a==b)cmn=it[mk(a,b)];
            else cmn=it[mk(a,b)]+countbig(a,b);
            io.print(sz[a]+sz[b]-cmn);
        }
    }
    return 0;
}
