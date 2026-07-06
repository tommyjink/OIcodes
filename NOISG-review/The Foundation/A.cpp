#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,a,b;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        if(i%a==0)cout<<"Fizz";
        if(i%b==0)cout<<"Buzz";
        if(i%a&&i%b)cout<<i;
        cout<<endl;
    }
    return 0;
}