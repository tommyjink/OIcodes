#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=105;
int n,k,tot,head[N];
struct node
{
    int to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node){y,head[x]};
    head[x]=tot;
}
void solve()
{
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}