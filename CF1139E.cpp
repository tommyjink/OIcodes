#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int tot,head[N];
vector<pii> g;
struct node
{
    int to,next;
}e[N*4];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}