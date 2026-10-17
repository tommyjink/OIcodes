#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2010,P=998244353;
int n,m,k,ans;
int f[5][N][N];
bool a[N];
string s[N],t[N];

inline int qpow(int x)
{
    x%=P;
    if(k==1)return x;
    int x2=x*x%P;
    if(k==2)return x2;
    int x3=x2*x%P;
    if(k==3)return x3;
    int x4=x2*x2%P;
    if(k==4)return x4;
    if(k==5)return x4*x%P;
    if(k==6)return x3*x3%P;
    if(k==7)return x3*x4%P;
    int x8=x4*x4%P;
    if(k==8)return x8;
    if(k==9)return x8*x%P;
    int x5=x4*x%P;
    return x5*x5%P;
}

void cal()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[1][i][j]+=f[1][i-1][j];
            f[3][i][j]+=f[3][i-1][j];
        }
}
void cal1()
{
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<f[1][i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"!!!!____"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>s[i];
    if(n>m)
    {
        for(int j=0;j<m;j++)
        {
            t[j+1].resize(n);
            for(int i=1;i<=n;i++)t[j+1][i-1]=s[i][j];
        }
        swap(n,m);
        for(int i=1;i<=n;i++)s[i]=t[i];
    }
    for(int x1=1;x1<=n;x1++)
    {
        for(int j=1;j<=m;j++)a[j]=1;
        for(int x2=x1;x2<=n;x2++)
        {
            for(int j=1;j<=m;j++)a[j]&=(s[x2][j-1]=='1');
            int *p1=f[1][x1],*p2=f[1][x2+1];
            int *p3=f[2][x1],*p4=f[3][x1];
            int *p5=f[3][x2+1],*p6=f[4][x1];
            int l=1;
            while(l<=m)
            {
                while(l<=m&&!a[l])l++;
                int r=l;
                while(r<=m&&a[r])r++;
                int x=r-l,y=x,cnt=1;
                for(int j=l;j<r;j++)
                {
                    p1[j]+=x;
                    p2[j]-=x;
                    p3[j]+=x;
                    p4[j]+=y;
                    p5[j]-=y;
                    p6[j]+=y;
                    x+=(r-l)-2*cnt;
                    y--;
                    cnt++;
                }
                l=r+1;
            }
        }
    }
    cal();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x=f[1][i][j];
            int y=x-f[2][i][j];
            int z=x-f[3][i][j];
            int w=x-f[2][i][j]-f[3][i][j]+f[4][i][j];
            ans=(ans+qpow(x)-qpow(y)-qpow(z)+qpow(w))%P;
        }
    cout<<(ans+P)%P<<endl;
    return 0;
}
