#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N];
deque<int> dq;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        while(!dq.empty()&&a[dq.back()]>=a[i])
            dq.pop_back();
        while(!dq.empty()&&dq.front()<=i-k)
            dq.pop_front();
        dq.push_back(i);
        if(i>=k)cout<<a[dq.front()]<<" ";
    }
    cout<<endl;
    while(!dq.empty())dq.pop_back();
    for(int i=1;i<=n;i++)
    {
        while(!dq.empty()&&a[dq.back()]<=a[i])
            dq.pop_back();
        while(!dq.empty()&&dq.front()<=i-k)
            dq.pop_front();
        dq.push_back(i);
        if(i>=k)cout<<a[dq.front()]<<" ";
    }
    return 0;
}