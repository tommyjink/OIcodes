#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[5];
    for(int i=1;i<=3;i++)
        cin>>a[i];
    sort(a+1,a+1+3);
    if(a[3]-a[1]>=10)cout<<"check again"<<endl;
    else cout<<"final "<<a[2]<<endl;
    return 0;
}