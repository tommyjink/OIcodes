#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int x[N],y[N],n=1e5;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<=n;i++)
        x[i]=y[i]=i-1;
    for(int i=1;i<=n;i+=1e3)
    {
        int l=i,r=i+1e3-1;
        while(y[i]>0)y[i]--,x[i]++;
        for(int j=l;j<=r;j+=10)
        {
            int jj=j+9;
            if(j!=l)
            {
                while(x[j]>x[i])x[j]--,y[j]++;
                while(x[j]<x[i])x[j]++,y[j]--;
            }
            for(int k=j+1;k<=jj;k++)
            {
                y[k]=y[k-1]+1;
                x[k]=x[k-1]+1;
            }
        }
    }
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
        cout<<x[i]<<" "<<y[i]<<endl;
    return 0;
}