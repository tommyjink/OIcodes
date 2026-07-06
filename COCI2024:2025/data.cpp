#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int rd(int x,int y)
{
    int z=y-x;
    return x+rand()%(z+1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    freopen("test.in","w",stdout);
    int n=5,m=5;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(rd(1,4)==1)
                cout<<"#";
            else cout<<".";
        }
        cout<<endl;
    }
    
    return 0;
}