#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,nxt[N],c[N],top=0;
string s,t;
stack<int> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s>>t;
    n=s.length();
    m=t.length();
    s=" "+s;
    t=" "+t;
    for(int i=2,j=0;i<=m;i++)
    {
        while(j&&t[j+1]!=t[i])j=nxt[j];
        if(t[j+1]==t[i])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=n;i++)
    {   
        if(st.empty())j=0;
        else j=c[st.top()];
        while(j&&s[i]!=t[j+1])j=nxt[j];
        if(s[i]==t[j+1])j++;
        st.push(i);
        c[i]=j;
        if(j==m)
        {
            int now=m;
            while(!st.empty()&&now--)st.pop();
        }
    }
    string ans;
    while(!st.empty())
        ans.push_back(s[st.top()]),st.pop();
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}