#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int gcd(int x,int y)
{
    if(x<y)swap(x,y);
    return y==0?x:gcd(y,x%y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,z,k;
        cin>>x>>y>>z>>k;
        cout<<gcd(x,gcd(y,gcd(z,k)))<<endl;
    }
    return 0;
}