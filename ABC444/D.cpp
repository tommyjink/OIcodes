#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[1]++;
        a[x+1]--;
    }
    int tag=0;
    for(int i=1;i<N;i++)
        a[i]+=a[i-1];
    int cnt=0,i=1;
    while(tag+a[i])
    {
        a[i]+=tag;
        tag=a[i]/10;
        a[i]%=10;
        cnt++;
        i++;
    }
    for(int i=cnt;i>=1;i--)
        cout<<a[i];
    return 0;
}