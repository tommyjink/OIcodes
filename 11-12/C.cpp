#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100;
int n,a[N],b[N];
bool ch(int l,int r)
{
    int p1=n,p2=n+2,c1=0,c2=0;
    for(int i=1;i<=p1;i++)
        if(a[i]<l||a[i]>r)c1++;
    for(int i=p2;i<=2*n+1;i++)
        if(a[i]<l||a[i]>r)c2++;
    int now1=0,now2=0;
    while(p1>=1&&p2<=2*n+1)
    {
        // cout<<p1<<","<<p2<<endl;
        if((a[p1]>=l&&a[p1]<=r)&&c2==0)
            return false;
        else if((a[p2]>=l&&a[p2]<=r)&&c1==0)
            return false;
        else if((a[p1]>=l&&a[p1]<=r)&&c2)
            c2--,now2++,p1--;
        else if((a[p2]>=l&&a[p2]<=r)&&c1)
            c1--,now1++,p2++;
        else if(a[p2]<l||a[p2]>r)p2++,p1--,c2--,c1--;
        while(p1>=1&&(a[p1]<l||a[p2]>r)&&now1)
            now1--,p1--;
        while(p2<=2*n+1&&(a[p2]<l||a[p2]>r)&&now2)
            now2--,p2++;
    }
    if(p1>=1&&a[p1]<=r&&a[p1]>=l)return false;
    if(p2<=2*n+1&&a[p2]<=r&&a[p2]>=l)return false;
    // cout<<l<<" "<<r<<" "<<c1<<" "<<c2<<" "<<p1<<" "<<p2<<endl;
    // cout<<l<<","<<r<<endl;
    return true;
}   
bool check(int mid)
{
    for(int i=1;i<=2*n+1-mid+1;i++)
    {
        int j=i+mid-1;
        if(ch(i,j))return true;
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=2*n+1;i++)
        cin>>a[i];
    int l=1,r=2*n+1;
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
    return 0;
}
/*

3
4 7 3 6 1 2 5
3
7
1 15 2 14 3 13 4 12 5 11 6 10 7 9 8
8
1
1 2 3
2

3
1 7 6 5 4 3 2 

2
1 5 2 4 3



7
1 8 2 14 3 15 6 10 7 9 13 4 12 5 11 
7
*/