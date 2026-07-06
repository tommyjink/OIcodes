#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
stack<int> st;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;cin>>q;
    for(int i=1;i<=100;i++)
        st.push(0);
    while(q--)
    {
        int ch;
        cin>>ch;
        if(ch==1)
        {
            int x;cin>>x;
            st.push(x);
        }
        else
        {
            if(!st.empty())
            {
                cout<<st.top()<<endl;
                st.pop();
            }
        }
    }
    return 0;
}