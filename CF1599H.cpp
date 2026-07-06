#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    int a,b,c,d;
    cout<<"? 1 1"<<endl;
    cout<<"? 1 1000000000"<<endl;
    cout<<"? 1000000000 1"<<endl;
    cin>>a>>b>>c;
    int x=(a+b-1000000000+1)/2;
    cout<<"? 1 "<<a-x+1<<endl;
    cin>>d;
    int X=1000000000-(c-(a-d)),Y=1000000000-(b-d);
    cout<<"! "<<d+1<<" "<<a-d+1<<" "<<X<<" "<<Y<<endl;
    return 0;
}