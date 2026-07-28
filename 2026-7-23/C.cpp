#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4005;
int m,n,k,x[N],y[N];
int fa[N],col[N];
vector<int> v[N];
int getfa(int x)
{
    if(x==fa[x])return x;
    return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x!=y)fa[x]=y;
}
bool check(int i,int j)
{
    if(abs(x[i]-x[j])>k)return true;
    if(abs(y[i]-y[j])>k)return true;
    return false;
}
void solve12()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(check(i,j))merge(i,j);
    for(int i=1;i<=n;i++)
        v[getfa(i)].push_back(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<v[i].size();j++)
            for(int k=j+1;k<v[i].size();k++)
                if(check(v[i][j],v[i][k]))
                {
                    if(!col[v[i][j]]&&!col[v[i][k]])
                        
                }
    }
}
void solve3()
{

}
void solve4()
{

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n>>k;
    if(m==2)solve12();
    else if(m==3&&n<=14)solve3();
    else if(m==3&&n<=4000)solve4();
    return 0;
}