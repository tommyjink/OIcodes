#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef unsigned short us;
const int N=4e5+10;
const int M=(1<<16);
int n,m,lastans,mp[256],pc[M],tag[N],tim;
us s[N][16],a[16];
vector<signed> ve[16][M];
ull myRand(ull &k1,ull &k2)
{
    ull k3=k1,k4=k2;
    k1=k4;
    k3^=(k3<<23);
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
void gen(int n,ull a1,ull a2)
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<16;j++)
        {
            s[i][j]=0;
            for(int k=0;k<16;k++)
                s[i][j]=(s[i][j]<<1)|((myRand(a1,a2)&(1ull<<32))?1:0);
            ve[j][s[i][j]].push_back(i);
        }
}
int check(int x,int k)
{
    int now=0;
    for(int i=0;i<16;i++)
    {
        now+=pc[s[x][i]^a[i]];
        if(now>k)return 0;
    } 
    return 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<M;i++)pc[i]=__builtin_popcount(i);
    for(char c='0';c<='9';c++)mp[(int)c]=c-'0';
    for(char c='A';c<='F';c++)mp[(int)c]=c-'A'+10;
    ull a1,a2;
    cin>>n>>m>>a1>>a2;
    gen(n,a1,a2);
    while(m--)
    {
        string str;int k;
        cin>>str>>k;
        for(int i=0;i<16;i++)
        {
            a[i]=0;
            for(int j=i*4;j<i*4+4;j++)
                a[i]=(a[i]<<4)|mp[(int)str[j]];
            if(lastans)a[i]^=65535;
        }
        ++tim;
        int ans=0;
        for(int i=0;i<16&&!ans;i++)
            for(auto x:ve[i][a[i]])
            {
                if(tag[x]==tim)continue;
                tag[x]=tim;
                if(check(x,k))
                {
                    ans=1;
                    break;
                }
            }
        cout<<ans<<endl;
        lastans=ans;
    }
    return 0;
}
