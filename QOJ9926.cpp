#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=205;
int n,m,a[N][N],x,y,now=0,b[N][N];
string ans[405];

void op(char c)
{
    ans[now].push_back(c);
    if(c=='R')y++;
    if(c=='D')x++;
    a[x][y]^=1;
}

bool work(int k)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=b[i][j];

    now=0;

    for(int d=m-2;d>=1-n;d--)
    {
        int tag=1;

        for(int i=1;i<=n;i++)
        {
            int j=i+d+1;
            if(j>=1&&j<=m&&a[i][j]!=k)
                tag=0;
        }

        if(tag)continue;

        now++;
        ans[now]="";
        a[1][1]^=1;
        x=y=1;

        while(y-x<d)op('R');
        while(y-x>d)op('D');

        while(x+1<=n&&y+1<=m)
        {
            if(a[x][y+1]!=k)
                op('R'),op('D');
            else
                op('D'),op('R');
        }

        while(x<n)op('D');
        while(y<m)op('R');
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]!=k)
                return false;

    return true;
}

void answ()
{
    cout<<"YES"<<endl;
    cout<<now<<endl;
    for(int i=1;i<=now;i++)
        cout<<ans[i]<<endl;
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='W')b[i][j]=0;
            else b[i][j]=1;
        }
    }

    if(work(0))answ();
    else if(work(1))answ();
    else cout<<"NO"<<endl;
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