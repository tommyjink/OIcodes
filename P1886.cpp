#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N],mn[N],mx[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    deque<int> q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(!q.empty()&&a[q.back()]>=a[i])q.pop_back();
        q.push_back(i);
        while(!q.empty()&&q.front()<=i-k)q.pop_front();
        mn[i]=a[q.front()];
    }
    while(!q.empty())q.pop_back();
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&a[q.back()]<=a[i])q.pop_back();
        q.push_back(i);
        while(!q.empty()&&q.front()<=i-k)q.pop_front();
        mx[i]=a[q.front()];
    }
    for(int i=k;i<=n;i++)
        cout<<mn[i]<<" ";
    cout<<endl;
    for(int i=k;i<=n;i++)
        cout<<mx[i]<<" ";
    cout<<endl;
    return 0;
}