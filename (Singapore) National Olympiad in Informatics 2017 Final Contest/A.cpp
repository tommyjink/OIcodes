#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int x[N],y[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    cout<<x[(n+1)/2]<<" "<<y[(n+1)/2]<<endl;
    return 0;
}