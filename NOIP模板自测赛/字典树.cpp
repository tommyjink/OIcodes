#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=3e6+10;
int nxt[N][100],tot=0,cnt[N];
string s[N];
int cal(char c)
{
    if(c>='0'&&c<='9')return c-'0';
    if(c>='a'&&c<='z')return 11+c-'a';
    if(c>='A'&&c<='Z')return 40+c-'A';
    return 0;
}
void insert(const string &s)
{
    int len=s.length(),p=0;
    for(int i=0;i<len;i++)
    {
        int ch=cal(s[i]);
        if(!nxt[p][ch])nxt[p][ch]=++tot;
        p=nxt[p][ch];
        cnt[p]++;
    }
}
int find(const string &s)
{
    int len=s.length(),p=0;
    for(int i=0;i<len;i++)
    {
        int ch=cal(s[i]);
        if(!nxt[p][ch])return 0;
        p=nxt[p][ch];
    }
    return cnt[p];
}
void del()
{
    for(int i=0;i<=tot;i++)
    {
        cnt[i]=0;
        memset(nxt[i],0,sizeof(nxt[i]));
    }
    tot=0;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        insert(s[i]);
    }
    while(q--)
    {
        string t;
        cin>>t;
        cout<<find(t)<<endl;
    }
    del();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
/*
3
3 3
fusufusu
fusu
anguei
fusu
anguei
kkksc
5 2
fusu
Fusu
AFakeFusu
afakefusu
fusuisnotfake
Fusu
fusu
1 1
998244353
9




2
1
0
1
2
1

*/