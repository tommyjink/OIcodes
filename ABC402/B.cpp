#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
queue<int> q;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x;
            q.push(x);
        }
        else
        {
            cout<<q.front()<<endl;
            q.pop();
        }
    }
    return 0;
}