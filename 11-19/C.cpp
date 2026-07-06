#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e6+100;
int m,mp[N],sum=0,cnt=0;
int dx=2e6,now=1;
void add(int x)
{
    if(mp[x+dx]==now)return;
    mp[x+dx]=now;
    sum+=x;
    cnt++;
}
void mark(int x)
{
    if(mp[x+dx]==now-1)add(x);
}
signed main()
{
    // freopen("jihe.in","r",stdin);
    // freopen("jihe.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m;
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int n,x;
            cin>>n;
            for(int i=1;i<=n;i++)
                cin>>x,add(x);
        }
        else if(op==2)
        {
            now++;
            int n,x;
            cin>>n;
            sum=cnt=0;
            for(int i=1;i<=n;i++)
                cin>>x,mark(x);
        }
        else if(op==3){if(cnt) dx--,sum+=cnt;}
        else if(cnt) dx++,sum-=cnt;
        cout<<sum<<endl;
    }
    return 0;
}
/*

4
1 5 1 2 3 4 5
2 5 1 3 5 7 9
3
4

*/