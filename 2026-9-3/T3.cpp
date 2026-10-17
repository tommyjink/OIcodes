#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e6+10;
int n,m,nxt[N][3],tot,mx[N],lst[N];
void insert(string &s,int pos)
{
    int p=0;
    for(char c:s)
    {
        int cc=c-'a';
        if(!nxt[p][cc])nxt[p][cc]=++tot;
        p=nxt[p][cc];
        mx[p]=max(mx[p],pos-lst[p]-1);
        lst[p]=pos;
    }
}
int get(string &s)
{
    int p=0;
    for(char c:s)
    {
        int cc=c-'a';
        if(!nxt[p][cc])return n;
        p=nxt[p][cc];
    }
    return mx[p];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        insert(s,i);
    }
    for(int i=1;i<=tot;i++)mx[i]=max(mx[i],n-lst[i]);
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        cout<<get(s)<<endl;
    }
    return 0;
}
