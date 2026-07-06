#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N];
map<int,int> pos;
struct node{int x,y,z;};
vector<node> ans;
void swp0(int x,int y,int z)//x>=0,y=0,z=k
{
    if(x==y||x==z||y==z)return;
    ans.push_back({z,y,a[x]});
    ans.push_back({x,z,a[x]});
    swap(a[x],a[y]);
}
void swpk(int x,int y,int z)//x>=0,y=k,z=0
{
    if(x==y||x==z||y==z)return;
    ans.push_back({z,y,a[x]});
    ans.push_back({x,z,a[x]});
    swap(a[x],a[y]);
}
void solve()
{
    pos.clear();
    ans.clear();
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i],pos[a[i]]=i;
    int tag=0;
    for(int i=1;i<=n;i++)
    {
        if(pos.count(k-a[i])&&pos[k-a[i]]!=i)
        {
            tag=1;
            ans.push_back({i,pos[k-a[i]],a[i]});
            a[i]=0,a[pos[k-a[i]]]=k;
            swp(1,i,pos[k-a[i]]);
            swp(n,);
            break;
        }
    }
    if(!tag)
    {
        cout<<"-1"<<endl;
        return;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}