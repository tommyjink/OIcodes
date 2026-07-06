#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,cnt[N],a[N],b[N],ans=0;
stack<int> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i-1])
            cnt[a[i]]++,b[a[i]]++;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1]&&a[i])
        {
            if(b[a[i]]==1)
            {
                ans=max(ans,(int)st.size()+1);
            }
            else if(cnt[a[i]]==b[a[i]])
            {
                st.push(a[i]),ans=max(ans,(int)st.size());
            }
            else if(st.top()!=a[i])
            {
                cout<<"-1"<<endl;
                return 0;
            }
            else if(cnt[a[i]]==1)
            {
                st.pop();
            }
            cnt[a[i]]--;
        }
    }
    cout<<ans<<endl;
    return 0;
}