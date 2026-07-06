#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define min(x,y) (x<y?x:y)
using namespace std;
const int N=100,TT=1e15;
int n,num,a[N],b[N],ans=1e18;
string s;
void print()
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<char(b[i]);
    cout<<endl;
}
int cal(int n)
{
    vector<int> v;
    int now=0,mul=1,res=0;
    for(int i=1;i<=n;i++)
    {
        if(res>num)return 1e18;
        now=min(now,TT);
        now=now*10+a[i];
        if(b[i]=='+')res+=mul*now,now=0,mul=1;
        else if(b[i]=='*')mul*=now,now=0;
    }
    res+=mul*now;
    return res;
}
void dfs(int x,int cnt,int now,int mul,int res)
{
    if(cnt>ans||res>num)return;
    if(x==n)
    {
        now=min(now,TT);
        now=now*10+a[x];
        res+=mul*now;
        if(res==num)
            ans=min(ans,cnt);
        // if(cnt==ans&&res==num)print();
        return;
    }
    now=min(now,TT);
    now=now*10+a[x];
    // b[x]='*';
    dfs(x+1,cnt+1,0,mul*now,res);
    // b[x]='+';
    dfs(x+1,cnt+1,0,1,res+mul*now);
    // b[x]=' ';
    dfs(x+1,cnt,now,mul,res);
}
signed main()
{
    // freopen("puzzle.in","r",stdin);
    // freopen("puzzle.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>s)
    {
        cin>>num;
        if(num<0)return 0;
        n=s.length();
        for(int i=1;i<=n;i++)
            a[i]=s[i-1]-'0';
        ans=1e18;
        dfs(1,0,0,1,0);
        if(ans==1e18)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
/*


输入 
032089
5
333
9
11111111111111111111
6

11111111111111111111
20
00
-1
输出
3
2





111111111111111
20

*/