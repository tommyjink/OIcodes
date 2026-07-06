#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,len,a[N],id[N],tag[N],sum[N];
inline int l(int x){return (x-1)*len+1;}
inline int r(int x){return x*len;}
void add(int x,int y,int d)
{
    if(id[x]==id[y])
    {
        for(int i=x;i<=y;i++)a[i]+=d;
        return;
    }
    for(int i=id[x]+1;i<=id[y]-1;i++)tag[i]+=d,sum[i]+=d*(r(i)-l(i)+1);
    for(int i=x;i<=r(id[x]);i++)a[i]+=d;
    for(int i=l(id[y]);i<=y;i++)a[i]+=d;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    len=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        id[i]=(i-1)/len+1;
        sum[id[i]]+=a[i];
    }
    for(int t=1;t<=n;t++)
    {
        int op,l,r,c;
        cin>>op>>l>>r>>c;
        if(op==0)
        {
            add(l,r,c);
        }
        else
        {
            cout<<a[r]+tag[id[r]]<<endl;
        }
    }
    return 0;
}