#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,D,X,x[N],y[N],ans=0,Y;
vector<int> val[N];
vector<int> b;
priority_queue<int> q;
signed main()
{
    // freopen("P11650_17.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>D>>X;
    Y=X;
    
    for(int i=1;i<=n;i++)
        cin>>x[i],b.push_back(x[i]);
    b.push_back(X);
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    X=lower_bound(b.begin(),b.end(),X)-b.begin();
    for(int i=1;i<=n;i++)
    {
        x[i]=lower_bound(b.begin(),b.end(),x[i])-b.begin();
        cin>>y[i];val[x[i]].push_back(y[i]);
    }
    auto p=upper_bound(b.begin(),b.end(),D)-1;
    for(int i=0;i<=p-b.begin();i++)
        for(auto j:val[i])
            q.push(j);
    while(D<Y)
    {
        // cout<<p-b.begin()<<endl;
        if(q.empty())
        {
            cout<<"-1"<<endl;
            return 0;
        }
        D+=q.top(),q.pop();
        auto xx=upper_bound(b.begin(),b.end(),D)-1;
        for(int i=p-b.begin()+1;i<=xx-b.begin();i++)
            for(auto j:val[i])
                q.push(j);
        p=xx;ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 10 40
30 20 30 20 38
7 7 7 7 7
*/