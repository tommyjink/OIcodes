#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int seed=998244353,P=998244353;
int rnd()
{
    seed=(seed*91%P+10293)%P;
    return seed;
}
int rd(int x,int y)
{
    int z=y-x;
    if(z==0)return x;
    return x+(rnd()%z)*(rnd()%z)%(z+1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    seed=rand();
    freopen("test.in","w",stdout);
    cout<<"5 3"<<endl;
    cout<<"3 "<<rd(0,3)<<" "<<rd(0,3)<<" 3 2 1"<<endl;
    cout<<"3 "<<rd(0,10)<<" "<<rd(0,10)<<" 1 2 3"<<endl;
    return 0;
}