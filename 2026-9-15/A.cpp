#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=1e6+10;
int n,nxt[N][30],tot=0,cnt[N];
int mx[N],dep[N],ans=0;
void insert(string &s)
{
    int p=0;
    for(char c:s)
    {
        int cc=c-'a';
        if(!nxt[p][cc])nxt[p][cc]=++tot,dep[tot]=dep[p]+1;
        p=nxt[p][cc];
        cnt[p]++;
        if(dep[p]>mx[cnt[p]])
        {
            ans-=mx[cnt[p]]^cnt[p];
            mx[cnt[p]]=dep[p];
            ans+=mx[cnt[p]]^cnt[p];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ans+=i;
        string s;cin>>s;
        insert(s);
        cout<<ans<<endl;
    }
    return 0;
}