#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e6+10;
int n,m,tot,ch[N][3],lst[N],ans[N];

void insert(string s,int id)
{
    int p=0,len=s.size();
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!ch[p][c])ch[p][c]=++tot;
        p=ch[p][c];
        ans[p]=max(ans[p],id-lst[p]-1);
        lst[p]=id;
    }
}

int query(string s)
{
    int p=0,len=s.size();
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'a';
        if(!ch[p][c])return n;
        p=ch[p][c];
    }
    return ans[p];
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
    for(int i=1;i<=tot;i++)ans[i]=max(ans[i],n-lst[i]);
    while(m--)
    {
        string s;
        cin>>s;
        cout<<query(s)<<endl;
    }
    return 0;
}
