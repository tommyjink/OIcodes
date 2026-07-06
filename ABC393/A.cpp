#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int r=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin>>a>>b;
    if(a[0]=='s'&&b[0]=='f')r=2;
    if(a[0]=='s'&&b[0]=='s')r=1;
    if(a[0]=='f'&&b[0]=='f')r=4;
    if(a[0]=='f'&&b[0]=='s')r=3;
    cout<<r<<endl;
    return 0;
}