#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=(1<<24)+5;

int n,dp[N];
char s[5];

inline int read()
{
    int res=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))res=res*10+(ch^'0'),ch=getchar();
    return res;
}

signed main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        int u=0;
        for(int j=0;j<=2;j++)
            if(s[j]<='x')
                u|=(1<<(s[j]-'a'));
        dp[u]++;
    }
    for(int i=0;i<24;i++)
        for(int j=0;j<(1<<24);j++)
            if((1<<i)&j)
                dp[j]+=dp[j^(1<<i)];
    int ans=0;
    for(int i=0;i<(1<<24);i++)ans^=(n-dp[i])*(n-dp[i]);
    printf("%lld\n",ans);
    return 0;
}
