#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
bool cmp(int x,int y)
{
    // for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    // cout<<endl;
    cout<<"? "<<x<<" "<<y<<endl;
    cout.flush();
    int res;cin>>res;
    return res;
    cout<<(int)(a[x]<a[y])<<endl;
    return a[x]<a[y];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        a[i]=i;
    // midsort(1,n);
    // for(int i=1;i<=n;i++)
    //     b[a[i]]=i;
    int p1=n;
    while(p1>=2&&!cmp(p1-1,p1))p1--;
    int p2=p1;
    while(p2>=2&&cmp(p2-1,p2))p2--;
    int p3=p2;
    while(p3>=2&&!cmp(p3-1,p3))p3--;
    if(p1==1)
    {
        cout<<"! -1"<<endl;
        return;
    }
    if(p1<n)
    {
        for(int i=p1;i<=n;i++)
                
        sort(b+p1,b+1+n);
        int p=lower_bound(b+p1,b+1+n,b[p1-1])-b;
        swap(b[p],b[p1-1]);
        sort(b+p1,b+1+n);
        cout<<"! ";
        for(int i=1;i<=n;i++)
            cout<<a[b[i]]<<" ";
        cout<<endl;
        return;
    }
    p2=p3;
    if(p2==1)
    {
        cout<<"! -1"<<endl;
        return;
    }
    if(p2<n)
    {
        sort(b+p2,b+1+n);
        int p=lower_bound(b+p2,b+1+n,b[p2-1])-b;
        swap(b[p],b[p2-1]);
        sort(b+p2,b+1+n);
        cout<<"! ";
        for(int i=1;i<=n;i++)
            cout<<a[b[i]]<<" ";
        cout<<endl;
        return;
    }
    cout<<"! -1??????????????"<<endl;
    return;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}