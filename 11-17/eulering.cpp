#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,phi[N],vis[N],prime[N],tot=0;
void init()
{
    phi[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!vis[i])prime[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot;j++)
        {
            if(prime[j]*i>=N)break;
            vis[prime[j]*i]=true;
            if(i%prime[j]==0)
            {
                phi[prime[j]*i]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
}
signed main()
{
    freopen("eulering.in","r",stdin);
    freopen("eulering.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); 
    init();
    int n;
    while(cin>>n)
        cout<<phi[n]<<endl;
    return 0;
}
/*

【样例输入】
33
8657
3124
4324
45345
【样例输出】
20
7860
1400
2024
24176

*/