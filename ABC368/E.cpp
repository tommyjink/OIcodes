#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,m,x[N];
struct node
{
    int typ,val;
}a[N*2];
int head[N],tot=0;
struct node1
{
    int from,to,next;
}e[N*2];
void add(int x,int y)
{
    e[++tot]=(node1){x,y,head[x]};
    head[x]=tot;
}
bool cmp(node x,node y)
{
    return x.val==y.val?x.typ>y.typ:x.val<y.val;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>x[1];
    for(int i=1;i<=m;i++)
    {
        int A,B,S,T;
        cin>>A>>B>>S>>T;
        add(A,B);
        a[i]=(node){1,S};
        a[i+m]=(node){2,T};
    }
    sort(a+1,a+1+2*m,cmp);
    for(int i=1;i<=2*m;i++)
    {
        
    }
    return 0;
}