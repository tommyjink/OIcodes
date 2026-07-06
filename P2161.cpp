#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int INF=1e10;
int now=0;
struct node
{
    int l,r;
    bool operator <(const node &s)const
    {
        return r<s.l;
    }
};
set<node> s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    while(n--)
    {
        char op;
        cin>>op;
        if(op=='A')
        {
            int l,r,cnt=0;
            cin>>l>>r;
            auto p=s.find((node){l,r});
            while(p!=s.end())
            {
                s.erase(p);
                cnt++;
                p=s.find((node){l,r});
            }
            s.insert((node){l,r});
            cout<<cnt<<endl;
            now=now-cnt+1;
        }
        else
        {
            cout<<now<<endl;
        }
    }
    return 0;
}