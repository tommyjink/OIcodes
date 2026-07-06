#include <iostream>
#include <vector>
#define int long long
#define endl "\n"
using namespace std;
vector<int> a[20];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    for(int i=1;i<=17;i++)
    {
        a[i].resize(500,0);
        for(int j=0;j<=499;j++)
        {
            if(j%(i*i))continue;
            a[i][j]=1;
        }
    }
    vector<int> v(500,0);
    v[0]=1;
    for(int i=1;i<=17;i++)
    {
        vector<int> vv(500,0);
        for(int j=0;j<=499;j++)
        {
            for(int k=0;j+k<=499;k++)
            {
                vv[j+k]+=v[j]*a[i][k];
            }
        }
        v=vv;
    }
    while(cin>>n)
    {
        if(n==0)exit(0);
        cout<<v[n]<<endl;
    }
    return 0;
}