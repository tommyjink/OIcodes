#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,k,a[N],s[N],L[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n>>k)) return 0;
    int sum_s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        sum_s+=s[i];
    }
    int cnt=0;
    stack<int> st;
    vector<int> f(n+2,n+1);
    for(int i=n;i>=0;i--)
    {
        while(!st.empty()&&s[st.top()]>=s[i]) st.pop();
        if(!st.empty()) f[i]=st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++)
    {
        int first_bad=f[i-1];
        if(first_bad>i) cnt+=(first_bad-i);
    }
    cout<<"Good Intervals: "<<cnt<<(cnt==k?" (OK)":" (WRONG)")<<endl;
    cout<<"Weighted Sum: "<<sum_s<<(sum_s==n*(n+1)/2?" (OK)":" (WRONG)")<<endl;
    return 0;
}