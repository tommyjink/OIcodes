#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5;
int n,k,ans=0,cnt=0;
set<pair<int,int>> s;
struct node
{
    int x,y;
}a[N];
bool cmp(node x,node y)
{
    return x.x==y.x?x.y<y.y:x.x<y.x;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,cmp);
    // for(int i=1;i<=n;i++)
    //     cout<<a[i].x<<" ";
    // cout<<endl;
    int l=1,r=0;
    while(++r<=n)
    {
        // cout<<l<<"!!"<<r<<"!!"<<cnt<<endl;
        while(l<r&&a[r].x-a[l].x>=k)
            s.erase(make_pair(a[l].y,a[l].x)),l++;
        // for(auto i:s)
        //     cout<<i.first<<"&&&"<<i.second<<endl;
        auto i=s.insert(make_pair(a[r].y,a[r].x)).first,j=i;
        // cout<<i->first<<"!!!!"<<endl;
        if(i!=s.begin()&&a[r].y-(--i)->first<k)
            ans=(k-abs(a[r].y-i->first))*(k-abs(a[r].x-i->second)),cnt++;
            // cout<<l<<"!"<<r<<endl;
        if((++j)!=s.end()&&j->first-a[r].y<k)
            ans=(k-abs(j->first-a[r].y))*(k-abs(j->second-a[r].x)),cnt++;
    }
    if(cnt==0)cout<<"0"<<endl;
    else if(cnt==1)cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;
}