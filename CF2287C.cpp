#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int isprime(int x)
{   
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return i;
    return 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<isprime(30001)<<endl;
    return 0;
}