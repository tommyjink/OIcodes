#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=2005;
int n,m,now=0;
string s,t;
struct node
{
    int len=1;
    short a[2000]={0};
}f[2][N];
node operator +(node x,node y)
{
    node res;
    if(x.len<y.len)swap(x,y);
    res.len=x.len;
    int tag=0;
    for(int i=1;i<=res.len;i++)
    {
        res.a[i]=x.a[i]+y.a[i]+tag;
        tag=res.a[i]/10;
        res.a[i]%=10;
    }
    if(tag)res.a[++res.len]=1;
    return res;
}
void print(node x)
{
    for(int i=x.len;i>=1;i--)
        cout<<x.a[i];
}
bool check(char x,char y)
{
    if((x=='A'&&y=='T')||(x=='T'&&y=='A'))return true;
    if((x=='C'&&y=='G')||(x=='G'&&y=='C'))return true;
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s>>t;
    s=" "+s,t=" "+t;
    for(int i=0;i<=n;i++)
        f[now][i].a[1]=1;
    for(int i=1;i<=m;i++)
    {
        now^=1;
        f[now][0].len=1;
        f[now][0].a[1]=0;
        for(int j=1;j<=n;j++)
        {
            f[now][j]=f[now][j-1];
            if(check(t[i],s[j]))
                f[now][j]=f[now][j]+f[now^1][j-1];
            // printf("f[%d][%d]=",i,j);
            // print(f[now][j]);
            // cout<<endl;
        }
        
    }
    print(f[now][n]);
    return 0;
}

/*
10 3
CATCCGACGA
GCC
*/