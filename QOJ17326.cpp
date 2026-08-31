#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=505;
int n,a[N],b[N],c[N];
int query(int *a)
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    int res;cin>>res;
    return res;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(i!=j)c[j]=n;
        c[i]=1;
        int res1=query(c);
        if(res1>n){a[i]=1+res1;continue;}
        c[i]=2*n;
        int res2=query(c);
        if(res2>n){a[i]=2*n-res2;continue;}
        b[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!b[i])continue;
        for(int j=1;j<=n;j++)
        {
            c[j]=a[j];
            if(b[j])c[j]=n;
        }
        c[i]=1;
        int res=query(c);
        a[i]=res+1;
        b[i]=0;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    int fb=0;
    cin>>fb;
    return 0;
}