#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,num=0,minn=1e10,minnum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(next_permutation(a+1,a+1+n))
            for(int i=1;i<=n;i++)   
                cout<<a[i];
        else cout<<"-1";
        cout<<endl;
    }
    return 0;
}