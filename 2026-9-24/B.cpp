#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int tot=0;
struct node
{
    int l,r,rd,val;
}t[N];
int newnode(int val)
{
    t[++tot]=(node){0,0,val};
    return tot;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}