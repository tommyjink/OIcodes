#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    multiset<int> s;
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        else
        {
            cout<<*s.begin()<<endl;
            s.erase(s.begin());
        }
    }
    return 0;
}
/*
8
1 5
1 1
1 1
1 9
2
2
1 2
2

*/