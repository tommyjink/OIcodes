#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,x,y;
void solve()
{
    cin>>n>>x>>y;
    string s;
    cin>>s;
    x=abs(x),y=abs(y);
    int xx=0,yy=0;
    if(x+y==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    for(auto c:s)
    {
        if(c=='4')
        {
            if(x-xx>y-yy)xx++;
            else yy++;
        }
        else
        {
            if(x==xx)yy++;
            else if(y==yy)xx++;
            else xx++,yy++;
        }
        if(x==xx&&y==yy)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}