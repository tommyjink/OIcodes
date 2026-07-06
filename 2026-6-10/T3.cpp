#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
int n,k;
struct node
{
    int x,y,w;
};
vector<node> e;
void add(int x,int y,int w)
{
    e.push_back({x,y,w});
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    if((n==1&&k!=1)||(n>=2&&n<=4&&k<2))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if(k==n)
    {
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                add(i,j,1);
    }
    else if(!k)
    {
        for(int i=1;i<n;i++)
            add(i,i+1,1);
        add(1,n,1);
    }
    else if(k==1)
    {
        for(int i=1;i<n;i++)
            add(i,i+1,1);
        add(1,n,1);
        add(2,n,2);
    }
    else
    {
        int p=n-k+2;
        for(int i=1;i<p;i++)
            add(i,i+1,1);
        for(int i=p+1;i<=n;i++)
            add(2,i,1);
    }
    cout<<e.size()<<endl;
    for(auto i:e)
        cout<<i.x<<" "<<i.y<<" "<<i.w<<endl;
    return 0;
}
