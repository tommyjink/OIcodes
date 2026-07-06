#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e7+10;
int n,tag[N],k=0,b[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i*i<N;i++)
    {
        for(int j=i+1;i*i+j*j<N;j++)
        {
            tag[i*i+j*j]++;
        }
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(tag[i]==1)b[++k]=i;
    }
    cout<<k<<endl;
    for(int i=1;i<=k;i++)
        cout<<b[i]<<" ";
    return 0;
}