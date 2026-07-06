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
    cin>>n;
    return 0;
}