#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int tot=0,root[N],len[N];
struct node
{
    int l,r;
    char c;
}t[N*16];
int addnode(int x)
{
    t[++tot]=t[x];
    return tot;
}
int build(int l,int r)
{
    int now=++tot,mid=(l+r)>>1;
    if(l==r)return now;
    t[now].l=build(l,mid);
    t[now].r=build(mid+1,r);
    return now;
}
int modify(int now,int l,int r,int x,char c)
{
    now=addnode(now);
    if(l==r)
    {
        t[now].c=c;
        return now;
    }
    int mid=(l+r)>>1;
    if(x<=mid)t[now].l=modify(t[now].l,l,mid,x,c);
    else t[now].r=modify(t[now].r,mid+1,r,x,c);
    return now;
}
char query(int now,int l,int r,int x)
{
    if(l==r)return t[now].c;
    int mid=(l+r)>>1;
    if(x<=mid)return query(t[now].l,l,mid,x);
    else return query(t[now].r,mid+1,r,x);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    int cnt=0;
    root[0]=build(1,1e5);
    // cout<<root[0]<<endl;
    len[0]=0;
    while(t--)
    {
        char op;
        cin>>op;
        if(op=='T')
        {
            char c;
            cin>>c;
            cnt++;
            len[cnt]=len[cnt-1]+1;
            root[cnt]=modify(root[cnt-1],1,1e5,len[cnt],c);
        }
        else if(op=='Q')
        {
            int x;
            cin>>x;
            cout<<query(root[cnt],1,1e5,x)<<endl;
        }
        else
        {
            int x;
            cin>>x;
            cnt++;
            len[cnt]=len[cnt-x-1];
            root[cnt]=addnode(root[cnt-x-1]);
        }
        // cout<<cnt<<","<<root[cnt]<<endl;
    }
    return 0;
}
/*

输入 输出
7
T a
T b
T c
Q 2
U 2
T c
Q 2


b
c

*/