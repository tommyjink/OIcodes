#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=15;
int n,k,a[N],len[N];
int phi(int x)
{
    int ans=x;
    for(int i=2;i*i<=x;i++){
        if(x%i)continue;
        ans=ans/i*(i-1);
        while(x%i==0)x/=i;
    }
    if(x>1)ans=ans/x*(x-1);
    return ans;
}
bool dfs(int d,int x,int y)
{
    if(x+y==n+2){
        if(--k)return false;
        int cnt=0;
        for(int i=1;i<=d;i++){
            if(i==1||a[i]!=a[i-1])len[++cnt]=0;
            len[cnt]++;
        }
        cout<<cnt<<" "<<a[1];
        for(int i=1;i<=cnt;i++)cout<<" "<<len[i];
        cout<<endl;
        return true;
    }
    a[d+1]=0;
    if(2*x+y<=n+2&&dfs(d+1,x,x+y))return true;
    a[d+1]=1;
    return x+2*y<=n+2&&dfs(d+1,x+y,y);
}
void solve()
{
    cin>>n>>k;
    if(k==-1)cout<<phi(n+2)<<endl;
    else if(n>10||!dfs(0,1,1))cout<<-1<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}