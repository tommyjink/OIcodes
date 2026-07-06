#include"archaeologist.h"
#include<bits/stdc++.h>
using namespace std;
int clampv(int x,int L)
{
    if(x<0)return 0;
    if(x>L)return L;
    return x;
}
void archaeologist(int N,int K,int L,vector<int> map,int lightlevel,vector<int> paths)
{
    vector<vector<int> > g(N);
    vector<int> leaf(N,0),deg(N,0);
    for(int i=1;i<N;i++)g[map[i]].push_back(i);
    queue<int> q;
    for(int i=0;i<N;i++)
    {
        deg[i]=g[i].size();
        if(deg[i]==0)q.push(i),leaf[i]=1;
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:g[u])leaf[u]+=leaf[v];
        if(map[u]!=-1)
        {
            deg[map[u]]--;
            if(deg[map[u]]==0)q.push(map[u]);
        }
    }
    int u=0;
    vector<int> cur=paths;
    while(!cur.empty())
    {
        int has0=-1,tv=0,rleft=0,vac=0;
        for(int i=0;i<(int)cur.size();i++)
        {
            rleft+=L-cur[i];
            if(cur[i]!=0)tv++;
            else has0=i;
            if(cur[i]!=L)vac=i;
        }
        pair<int,vector<int> > nxt;
        if(has0==-1)
        {
            set_light(clampv(L-rleft+1,L));
            nxt=take_path(vac);
        }
        else
        {
            set_light(clampv(L-leaf[u]+tv+1,L));
            nxt=take_path(has0);
        }
        u=nxt.first;
        cur.swap(nxt.second);
    }
    set_light(L);
}
