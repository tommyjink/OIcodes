#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1024;
int n,u,b[N],c[N],cnt=0;
int sav[N];
char ask(int s1,int s2)
{
    cout<<"? "<<s1<<" "<<s2<<endl;
    char res;cin>>res;
    return res;
}
void out(int ans)
{
    int cnt=__builtin_popcount(ans);
    cout<<"! "<<cnt<<" ";
    for(int i=1;i<=n;i++)
        if(ans&(1<<(i-1)))cout<<i<<" ";
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
            c[cnt]=c[cnt-1]|(1<<(i-1));
        }
    }
    int l=0,r=cnt;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(ask(c[mid]|(1<<(u-1)),c[mid])!='<')l=mid;
        else r=mid-1;
    }
    if(l==0)out(0);
    
    return 0;
}