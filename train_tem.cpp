#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,head[N],tot=0;
struct node
{
    int to,next;
}e[N*2];
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