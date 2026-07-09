#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N],p[N],b[N],tag[N],c[N];
vector<vector<int>> ans;
void print()
{
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
    int now=0;
    for(int i=1;i<=n;i++)
    {
        b[i]=now;
        if(i<n&&p[i]>p[i+1])now++;
    }
    int m=ceil(log2(now+1));
    cout<<m<<endl;
    print();
    for(int i=0;i<m;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(!(b[j]&(1ll<<i)))tag[j]=0;
            else tag[j]=1;
        }
        for(int j=1;j<=n;j++)
            if(!tag[a[j]])c[++cnt]=a[j];
        for(int j=1;j<=n;j++)
            if(tag[a[j]])c[++cnt]=a[j];
        for(int j=1;j<=n;j++)
            a[j]=c[j];
        print();
    }
    return 0;
}
/*
Permutation:3 4 5 6 2 1
Pos:6 5 1 2 3 4

*/