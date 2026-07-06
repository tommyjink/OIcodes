#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1200000;
const double pi=acos(-1);
int c[5],n,d[5],s;
int r[N],limit=1<<20,l=20;
struct Complex
{
    double x,y;
    Complex(double xx=0,double yy=0){x=xx,y=yy;}
}a[N],b[N];
Complex operator +(Complex a,Complex b){return {a.x+b.x,a.y+b.y};}
Complex operator -(Complex a,Complex b){return {a.x-b.x,a.y-b.y};}
Complex operator *(Complex a,Complex b){return {a.x*b.x-a.y*b.y,a.y*b.x+a.x*b.y};}
void fft(Complex *A,int type)
{
    for(int i=0;i<limit;i++)
        if(i<r[i])swap(A[i],A[r[i]]);
    for(int len=1;len<limit;len<<=1)
    {
        Complex Wn(cos(pi/len),sin(pi/len)*type);
        for(int i=0;i<limit;i+=(len<<1))
        {
            Complex w(1,0);
            for(int j=0;j<len;j++,w=w*Wn)
            {
                Complex x=A[i+j],y=w*A[i+len+j];
                A[i+j]=x+y,A[i+len+j]=x-y;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<limit;i++)
        r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    b[0]={1,0};
    fft(b,1);
    for(int i=1;i<=4;i++)
    {
        cin>>c[i];
        for(int j=0;j<limit;j++)a[j]={0,0};
        for(int j=0;j*c[i]<=100000;j++)
            a[j*c[i]]={1,0};
        fft(a,1);
        for(int j=0;j<limit;j++)
            b[j]=b[j]*a[j];
    }
    fft(b,-1);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=4;j++)cin>>d[j];
        cin>>s;
        int ans=0;
        for(int j=0;j<(1ll<<4);j++)
        {
            int p=0,cnt=0;
            for(int k=1;k<=4;k++)
                if(j&(1ll<<(k-1)))
                    cnt++,p+=(c[k]*(d[k]+1));
            if(p>s)continue;
            int val=(int)(b[s-p].x/limit+0.5);
            if(cnt&1)ans-=val;
            else ans+=val;
        }
        cout<<ans<<endl;
    }
    return 0;
}