#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];string s;
void solve()
{
    stack<int> st;
    cin>>s;
    n=s.length();
    for(auto i:s)
    {
        if(!st.empty()&&i-'0'==st.top())st.pop();
        else st.push(i-'0');
    }
    int now=0;
    while(!st.empty())a[++now]=st.top(),st.pop();
    for(int i=1;i<=n;i+=2)
        if(a[i]==1)a[i]=0;
        else if(a[i]==0)a[i]=1;
    int cnt[3]={0,0};
    for(int i=1;i<=n;i++)
        cnt[a[i]]++;
    while(cnt[2])
    {
        if(cnt[0]>=cnt[1])cnt[1]++,cnt[2]--;
        else cnt[0]++,cnt[2]--;
    }
    cout<<abs(cnt[1]-cnt[0])<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}