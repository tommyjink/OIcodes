#include<bits/stdc++.h>
#define int long long
#define bit bitset<N> 
using namespace std;
const int N=1024;
int n,u,b[N],cnt=0;
bit c[N],ans;
char sav[N];
void print(bit x)
{
    for(int i=1;i<=n;i++)
        cout<<x[i];
    cout<<" ";
}
char ask(bit s)
{
    bit s1=s,s2=s;
    s1[u]=1;
    cout<<"? ";
    print(s1);
    print(s2);
    cout<<endl;
    char res;cin>>res;
    return res;
}
void out(bit ans)
{
    int cnt=ans.count();
    cout<<"! "<<cnt<<" ";
    for(int i=1;i<=n;i++)
        if(ans[i])cout<<i<<" ";
    cout<<endl;
    exit(0);
}
signed main()
{
    cin>>n>>u;
    for(int i=1;i<=n;i++)
    {
        if(i!=u)
        {
            b[++cnt]=i;
            c[cnt]=c[cnt-1];
            c[cnt][i]=1;
        }
    }
    if(ask(0)=='=')out(0);
    int l=0,r=cnt;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        sav[mid]=ask(c[mid]);
        if(sav[mid]!='<')l=mid;
        else r=mid-1;
    }
    bit A=c[l],B=c[l+1];
    if(l>0&&sav[l]=='=')
    {
        for(int i=1;i<=n;i++)
        {
            if(i==u)continue;
            bit C=A;
            C[i]=C[i]^1;
            if(ask(C)!='=')ans[i]=1;
        }
        out(ans);
    }
    else
    {
        int w=b[l+1];
        ans[w]=1;
        for(int i=1;i<=n;i++)
        {
            if(i==u||i==w)continue;
            if(A[i]==1)
            {
                bit C=B;
                C[i]=0;
                if(ask(C)!='<')ans[i]=1;
            }
            else
            {
                bit C=A;
                C[i]=1;
                if(ask(C)!='>')ans[i]=1;
            }
        }
        out(ans);
    }
    return 0;
}