#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int A,B,X,Y,a[N],b[N],n,m;
int gcd(int x,int y)
{
    if(!y)return x;
    return gcd(y,x%y);
}
int cal(int A,int X,int *a,int &n)
{
    n=0;
    int d=gcd(A,X);
    if(__builtin_popcountll(A/d)!=1)return -1;
    while(X&&X!=A)
    {
        // cout<<X<<"!"<<endl;
        if(X<A-X)a[++n]=1,X=2*X;
        else a[++n]=2,X=2*X-A;
    }
    // reverse(a+1,a+1+n);
    return X;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>A>>B>>X>>Y;
    int x=cal(A,X,a,n),y=cal(B,Y,b,m);
    if(x==-1||y==-1)cout<<"-1",exit(0);
    while(n<m)a[++n]=(x==A?2:1);
    while(m<n)b[++m]=(y==B?2:1);
    reverse(a+1,a+1+n);
    // return 0;
    reverse(b+1,b+1+m);
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        int xx=0,yy=0;
        if(a[i]==2)xx=A;
        if(b[i]==2)yy=B;
        cout<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
        x=(xx+x)/2;
        y=(yy+y)/2;
    }
    return 0;
}