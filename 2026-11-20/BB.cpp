#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e5+10;
int n,a[N],b[N];
bool check(int l,int mid)
{
    int now=0;
    for(int i=l;i<=l+n-1;i++)
    {
        now=min(now+a[i],mid);
        now-=b[i];
        if(now<0)return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i],mx+=a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i],b[i+n]=b[i];
    int tag=1;
    for(int i=1;i<=n;i++)
        if(a[i]!=b[i])tag=0;
    if(tag)
    {
        deque<int> q;
        for(int i=1;i<2*n;i++)
        {
            while(!q.empty()&&q.front()<=i-n)q.pop_front();
            while(!q.empty()&&a[q.back()]<a[i])q.pop_back();
            q.push_back(i);
            if(i>=n)
            {
                cout<<a[q.front()]<<" ";
            }
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int l=0,r=mx;
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(check(i,mid))r=mid;
            else l=mid+1;
        }
        if(!check(i,l))cout<<"-1 ";
        else cout<<l<<" "; 
    }
    return 0;
}