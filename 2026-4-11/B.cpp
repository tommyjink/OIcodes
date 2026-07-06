#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5005,P=998244353;
int n,m,k,sz;
unsigned long long a[N][240];

int f(char c)
{
    if(c>='0'&&c<='9')return c-'0';
    return c-'A'+10;
}

void solve()
{
    cin>>n>>m>>k;
    sz=(m+63)/64;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        int bp=0,id=0;
        unsigned long long cur=0;
        for(char c:s)
        {
            cur=(cur<<4)|f(c);
            bp+=4;
            if(bp==64){
                a[i][id++]=cur;
                cur=0;
                bp=0;
            }
        }
        if(bp>0)a[i][id]=cur;
    }
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<i;j++)
        {
            int dif=0;
            for(int p=0;p<sz;p++)
            {
                dif+=__builtin_popcountll(a[i][p]^a[j][p]);
                if(dif>k)break;
            }
            if(dif<=k)cnt++;
        }
        if(!cnt){ans=0;break;}
        ans=ans*cnt%P;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(); 
    return 0;
}