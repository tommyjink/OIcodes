#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N];
stack<int> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[n-i+1];
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[i]>a[st.top()])st.pop();
        if(st.empty())b[i]=0;
        else b[i]=st.top();
        st.push(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=i-b[i]-1;
    // for(int i=1;i<=n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}