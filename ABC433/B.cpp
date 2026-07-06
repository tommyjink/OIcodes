#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
stack<int> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&a[st.top()]<=a[i])st.pop();
        if(st.empty())cout<<"-1"<<endl;
        else cout<<st.top()<<endl;
        st.push(i);
    }
    return 0;
}