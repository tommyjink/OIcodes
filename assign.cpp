#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=4e5+100,P=998244353;
int n,xx[N],yy[N],t[N],cx[N],cy[N],A[N],B[N];
int C[N],D[N],AA[N],BB[N],CC[N],DD[N],ans=0,tx=0,cnt=0;
struct node
{
    int x,y,num;
}a[N];
bool cmp(node x,node y)
{
    return x.x==y.x?x.y<y.y:x.x<y.x;
}
bool cmp1(node x,node y)
{
    return x.x==y.x?x.y<y.y:x.x>y.x;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i>0;i-=lowbit(i))
        res+=t[i];
    return res;
}
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=(res*x)%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        a[i].num=i;
        xx[i]=a[i].x;
        yy[i]=a[i].y;
    }
    // while(1)
    // {
    //     int ch,x;
    //     cin>>ch>>x;
    //     if(ch==1)add(x,1);
    //     else cout<<query(x)<<endl;
    // }
    sort(xx+1,xx+1+n);
    sort(yy+1,yy+1+n);
    for(int i=1;i<=n;i++)
    {
        a[i].x=lower_bound(xx+1,xx+1+n,a[i].x)-xx;
        a[i].y=lower_bound(yy+1,yy+1+n,a[i].y)-yy;
        cx[a[i].x]++;
        cy[a[i].y]++;
    }
    for(int i=1;i<=n;i++)
        cx[i]+=cx[i-1],
        cy[i]+=cy[i-1];
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(tx!=a[i].x)tx=a[i].x,cnt=0;
        cnt++;
        add(a[i].y,1);
        A[a[i].num]=query(a[i].y)-1;
        B[a[i].num]=cx[a[i].x]-query(a[i].y-1)-1;
        AA[a[i].num]=A[a[i].num]-(query(a[i].y)-query(a[i].y-1)-1)-(cnt-1);
        BB[a[i].num]=B[a[i].num]-(query(a[i].y)-query(a[i].y-1)-1)-(cx[a[i].x]-cx[a[i].x-1]-cnt);
    }
    sort(a+1,a+1+n,cmp1);
    memset(t,0,sizeof(t));
    tx=0;
    for(int i=1;i<=n;i++)
    {
        if(tx!=a[i].x)tx=a[i].x,cnt=0;
        cnt++;
        add(a[i].y,1);
        C[a[i].num]=query(a[i].y)-1;
        D[a[i].num]=cx[n]-cx[a[i].x-1]-query(a[i].y-1)-1;
        CC[a[i].num]=C[a[i].num]-(query(a[i].y)-query(a[i].y-1)-1)-(cnt-1);
        DD[a[i].num]=D[a[i].num]-(query(a[i].y)-query(a[i].y-1)-1)-(cx[a[i].x]-cx[a[i].x-1]-cnt);
        // printf("num=%lld,x=%lld,y=%lld,A%lld,B%lld,C%lld,D%lld\n",a[i].num,a[i].x,a[i].y,A[a[i].num],B[a[i].num],C[a[i].num],D[a[i].num]);
    }
    for(int i=1;i<=n;i++)
    {
        ans=(ans+qpow(2,n-1)+(qpow(2,A[i])-1)*(qpow(2,D[i])-1)%P*qpow(2,BB[i]+CC[i])%P)%P,
        ans=(ans+(qpow(2,B[i])-1)*(qpow(2,C[i])-1)%P*(qpow(2,AA[i]+DD[i]))%P)%P;
        
        // cout<<(qpow(2,A[i])-1)*(qpow(2,D[i])-1)%P*qpow(2,B[i]+C[i])<<" "<<ans<<endl;
        // cout<<(qpow(2,A[i])-1)*(qpow(2,D[i])-1)%P*qpow(2,B[i]+C[i])<<" "<<(qpow(2,B[i])-1)*(qpow(2,C[i])-1)%P*(qpow(2,A[i]+D[i]))%P<<" "<<i<<" "<<ans<<endl;
    }
    cout<<ans<<endl;
    // cout<<qpow(2,3);
    return 0;
}
/*

6
1 2
1 5
2 3
3 2
4 1
4 4

2
1 1
2 2

3
1 1
2 2
3 3

4
1 1
1 2
2 2
3 3
*/