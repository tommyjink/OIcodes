#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,op;
vector<int> t;
struct node{vector<int> mem,v;};
bool modify(const vector<int> a,vector<int> &v,int x)
{
    x--,v=a;
    if(x==0&&a[1]){v[1]--,v[0]++;return true;}
    if(x==n-1&&a[n-2]){v[n-2]--,v[n-1]++;return true;}
    if(x>0&&x<n-1&&a[x-1]&&a[x+1]){v[x-1]--,v[x+1]--,v[x]+=2;return true;}
    return false;
}
vector<int> bfs()
{
    vector<int> s(n,1),smem;
    queue<node> q;
    q.push({smem,s});
    while(!q.empty())
    {
        node now=q.front();q.pop();
        if(now.v==t)return now.mem;
        for(int i=1;i<=n;i++)
        {
            node tmp=now;
            if(modify(now.v,tmp.v,i))
            {
                tmp.mem.emplace_back(i);
                q.push(tmp);
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>op;
    t.assign(n,0);
    for(int i=0;i<n;i++)
        cin>>t[i];
    vector<int> mem=bfs(),now(n,1);
    for(auto i:now)cout<<i<<" ";
    cout<<endl;
    for(auto i:mem)
    {
        cout<<i<<":"<<endl;
        modify(now,now,i);
        for(auto j:now)cout<<j<<" ";
        cout<<endl;
    }
    for(auto i:mem)cout<<i<<" ";
    return 0;
}