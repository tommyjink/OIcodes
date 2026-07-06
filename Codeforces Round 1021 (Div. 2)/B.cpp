#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        if(k==0&&n%2==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        else if(n%2==1)
        {
            if(k%2==0)k--;
            int l=(n-k)/2,r=n-(n-k)/2+1;
            cout<<a[r]-a[l]+1<<endl;
        }
        else
        {
            if(k%2==1)k--;
            int l=(n-k)/2,r=n-(n-k)/2+1;
            // cout<<l<<" "<<r<<endl;
            cout<<a[r]-a[l]+1<<endl;
        }
    }
    return 0;
}

/*
4
4 0
1 2 3 4
5 2
1 6 6 7 7
3 1
6 7 9
6 2
1 2 5 9 10 13

2
2
4
9

*/