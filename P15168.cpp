#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=5010;
int n,m,a[N],t[N];
void add(int x,int d)
{
    if(!x)return;
    for(int i=x;i<N;i+=lowbit(i))
        t[i]+=d;
}
int sum(int l,int r)
{
    int res=0;
    for(int i=r;i>0;i-=lowbit(i))
        res+=t[i];
    for(int i=l-1;i>0;i-=lowbit(i))
        res-=t[i];
    return res;
}
void Alessia()
{
    cout<<"Alessia"<<endl;
    for(int i=1;i<=n;i++)
    {
        int l=1,b;
        while(sum(l,l+a[i]-1))l++;
        cout<<a[i]<<" "<<l<<endl;
        cin>>b;
        add(b,1);
    }
}
void Bernardo(int d)
{
    cout<<"Bernardo"<<endl;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>r>>l;
        r=l+r-1;
        for(int j=l;j<=r;j++)
            if(j%d==0||j==r)
            {
                cout<<j<<endl;
                add(j,1);
                break;
            }
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++)
        if(a[i]*i>m)Bernardo(a[i]),exit(0);
    Alessia();
    return 0;
}