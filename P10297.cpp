#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],pos[N],cnt=0;
struct node
{
    int l,r,num;
}c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        int j=i;
        while(b[i]==b[j]&&j<=n)j++;
        c[++cnt]=(node){i,j-1,b[i]};
        i=j-1;
    }
    int p=1;
    for(int i=1;i<=cnt;i++)
    {
        while(a[p]!=c[i].num&&p<=n)p++;
        if(p>n)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        pos[i]=p;
    }
    vector<node> v;
    for(int i=cnt;i>=1;i--)if(pos[i]<c[i].r)v.push_back((node){pos[i],c[i].r,1});
    for(int i=1;i<=cnt;i++)if(c[i].l<pos[i])v.push_back((node){c[i].l,pos[i],0});
    cout<<"YES"<<endl<<v.size()<<endl;
    for(auto i:v)cout<<(i.num?"R ":"L ")<<i.l-1<<" "<<i.r-1<<endl;
    return 0;
}