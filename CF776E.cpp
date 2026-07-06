#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int P=1e9+7;
int n,k;
int phi(int x)
{
    int res=x;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i)continue;
        res=res/i*(i-1);
        while(x%i==0)x/=i;
    }
    if(x>1)res=res/x*(x-1);
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=(k+1)/2&&n>1;i++)
        n=phi(n);
    cout<<n%P;
    // while(cin>>n)
    //     cout<<phi(n)<<endl;
    return 0;
}