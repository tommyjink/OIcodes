#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> a,b,c;
int cal(int x,int y)
{
    int res=0;
    while(x&&y)
    {
        if(x%10==y%10)res++;
        x/=10,y/=10;
    }
    return res;
}
void solve()
{
    int n,i,j;
    cin>>n>>i>>j;
    if(n==12)
    {
        // cout<<a[i-1]<<","<<a[j-1]<<endl;
        printf("%lldA%lldB\n",cal(a[i-1],a[j-1]),2-cal(a[i-1],a[j-1]));
        // cout<<cal(a[i-1],a[j-1])<<endl;
    }
    if(n==123)
    {
        // cout<<b[i-1]<<","<<b[j-1]<<endl;
        // cout<<cal(b[i-1],b[j-1])<<endl;
        printf("%lldA%lldB\n",cal(b[i-1],b[j-1]),3-cal(b[i-1],b[j-1]));
    }
    if(n==1234)
    {
        // cout<<c[i-1]<<","<<c[j-1]<<endl;
        // cout<<cal(c[i-1],c[j-1])<<endl;
        printf("%lldA%lldB\n",cal(c[i-1],c[j-1]),4-cal(c[i-1],c[j-1]));
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            if(i!=j)a.emplace_back(i*10+j);
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            for(int k=1;k<=3;k++)
                if(i!=j&&j!=k&&i!=k)
                    b.emplace_back(i*100+j*10+k);
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            for(int k=1;k<=4;k++)   
                for(int l=1;l<=4;l++)
                    if(i!=j&&j!=k&&i!=k&&i!=l&&j!=l&&k!=l)
                        c.emplace_back(i*1000+j*100+k*10+l);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}