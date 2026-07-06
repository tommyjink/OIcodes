#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e6+10;
int n,a[N],ans[N];
stack<int> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]<=a[i])st.pop();
        if(!st.empty())ans[i]=st.top();
        else ans[i]=0;
        st.push(i);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}