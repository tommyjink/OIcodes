#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int a[N],b[N];
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[a[i]]=i;
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(b[z]>y||b[z]<x)
        {
            cout<<"-1"<<" ";
            continue;
        }
        int l=x,r=y,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(mid==b[z])
            {
                l=r=mid;
                break;
            }
            else if(mid<b[z]&&a[mid]>z)l=mid+1,cnt1++;
            else if(mid<b[z])l=mid+1,cnt3++;
            else if(mid>b[z]&&a[mid]<z) r=mid-1,cnt2++;
            else r=mid-1,cnt4++;
        }
        if(cnt1>=z-cnt3||cnt2>=(n-z+1)-cnt4)
        {
            cout<<"-1"<<" ";
            continue;
        }
        else cout<<min(cnt1,cnt2)*2+abs(cnt1-cnt2)*2<<" ";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve(),cout<<endl;
    return 0;
}
/*
8
5 3
1 2 3 4 5
1 5 4
1 3 4
3 4 4

7 4
3 1 5 2 7 6 4
3 4 2
2 3 5
1 5 6
1 7 3

2 1
2 1
1 2 1

1 1
1
1 1 1

7 1
3 4 2 5 7 1 6
1 7 1

16 1
16 10 12 6 13 9 14 3 8 11 15 2 7 1 5 4
1 16 4

16 1
14 1 3 15 4 5 6 16 7 8 9 10 11 12 13 2
1 16 14

13 1
12 13 10 9 8 4 11 5 7 6 2 1 3
1 13 2




0 -1 0 
2 0 -1 4 
-1 
0 
-1 
-1 
-1 
-1 

*/