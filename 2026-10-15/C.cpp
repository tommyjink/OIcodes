#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10,M=205,P=998244353;
int n,q,p[N],pw[N],fa[M*2],f[M][M];
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    int inc=1,dec=1;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        if(p[i]!=i)inc=0;
        if(p[i]!=n-i+1)dec=0;
    }
    pw[0]=1;
    for(int i=1;i<=n+2;i++)pw[i]=pw[i-1]*2%P;
    if(n<=200)
    {
        for(int l=1;l<=n;l++)
        {
            for(int i=1;i<=2*n;i++)fa[i]=i;
            int cnt=0,ok=1;
            for(int r=l;r<=n;r++)
            {
                cnt++;
                for(int i=l;i<r;i++)
                {
                    if(p[i]<p[r])continue;
                    if(find(i)==find(r))
                    {
                        ok=0;
                        break;
                    }
                    if(find(i)!=find(r+n))
                    {
                        fa[find(i)]=find(r+n);
                        fa[find(i+n)]=find(r);
                        cnt--;
                    }
                }
                if(!ok)break;
                f[l][r]=pw[cnt];
            }
        }
        for(int l=n;l>=1;l--)
            for(int r=l;r<=n;r++)
                f[l][r]=(f[l][r]+f[l+1][r]+f[l][r-1]-f[l+1][r-1]+P)%P;
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int len=r-l+1;
        if(inc)cout<<(pw[len+2]-2*len-4+P)%P<<endl;
        else if(dec)cout<<4*len-2<<endl;
        else if(n<=200)cout<<f[l][r]<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
