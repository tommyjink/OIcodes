#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+10;
int n,m,t[N][N];
void add(int x,int y,int w)
{

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    while(m--)
    {
        int op,x,y,xx,yy;
        cin>>op>>x>>y>>xx>>yy;
        if(op==1)
            cout<<query(xx,yy)^query(x-1,yy)^query(xx,y-1)^query(x-1,y-1)<<endl;
        if(op==2)
        {
            int w;cin>>w;

        }
    }
    return 0;
}