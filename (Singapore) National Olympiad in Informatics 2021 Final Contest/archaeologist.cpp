#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,k,l,fa[N],c[N],u;
vector<int> g[N],p;
void archaeologist(int N, int K, int L, std::vector<int> map, int lightlevel, std::vector<int> paths);
std::pair<int, std::vector<int>> take_path(int corridor);
void set_light(int level);
int jd(int x)
{
    if(x<0)return 0;
    if(x>l)return l;
    return x;
}
int dfs(int x)
{
    if(g[x].empty())return c[x]=1;
    c[x]=0;
    for(int y:g[x])c[x]+=dfs(y);
    return c[x];
}
void archaeologist(int N,int K,int L,vector<int> map,int lightlevel,vector<int> paths)
{
    n=N,k=K,l=L;
    for(int i=0;i<n;i++)g[i].clear(),c[i]=0;
    for(int i=0;i<n;i++)fa[i]=map[i];
    for(int i=1;i<n;i++)g[fa[i]].push_back(i);
    dfs(0);
    u=0;
    p=paths;
    while(1)
    {
        int m=p.size();
        if(!m)
        {
            set_light(l);
            return;
        }
        int z=-1,v=0,s=0,w=0;
        for(int i=0;i<m;i++)
        {
            s+=l-p[i];
            if(p[i])v++;
            else z=i;
            if(p[i]!=l)w=i;
        }
        pair<int,vector<int> > t;
        if(z==-1)
        {
            set_light(jd(l-s+1));
            t=take_path(w);
        }
        else
        {
            set_light(jd(l-c[u]+v+1));
            t=take_path(z);
        }
        u=t.first;
        p.swap(t.second);
    }
}
