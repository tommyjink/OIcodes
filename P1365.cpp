#include<bits/stdc++.h>
#define int long long
#define t(x) x*x
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n;
string s;
double f[N],len=0.0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        switch (s[i])
        {
            case 'o':
                f[i]=f[i-1]+2.0*len+1.0,len=len+1.0;
                break;
            case 'x':
                f[i]=f[i-1],len=0.0;
                break;
            case '?':
                f[i]=f[i-1]+len+0.5,len=(len+1.0)/2.0;
                break;
        }
    }
    printf("%.4lf",f[n]);
    return 0;
}