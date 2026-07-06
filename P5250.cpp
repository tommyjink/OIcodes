#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
set<int> s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    while (m--)
    {
        int op, l;
        cin >> op >> l;
        if (op == 1)
        {
            if (s.find(l) == s.end())
                s.insert(l);
            else
                cout << "Already Exist" << endl;
        }
        else
        {
            if(s.empty())
            {
                cout<<"Empty"<<endl;
                continue;
            }
            auto it2 = s.lower_bound(l), it1 = it2;
            if (it2 != s.begin())it1 = prev(it2);
            if(it2==s.end())it2--;
            int x = *it1, y = *it2;
            // if(it2==s.end())cout<<"!!!"<<x<<" "<<y<<endl;
            if (abs(x - l) == abs(y - l))
            {
                cout << min(x, y) << endl;
                s.erase(min(x,y));
            }
            else if (l - x < y - l)
            {
                cout << x << endl;
                s.erase(x);
            }
            else
            {
                cout << y << endl;
                s.erase(y);
            }
        }
    }
    return 0;
}