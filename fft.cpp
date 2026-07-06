#include<bits/stdc++.h>
const int N=4e6+5;
const double pi=acos(-1);
int n,m,limit=1;
struct Complex {double x,y;}a[N],b[N];
inline Complex operator +(Complex a,Complex b) {return {a.x+b.x,a.y+b.y};}
il Complex operator -(Complex a,Complex b) {return {a.x-b.x,a.y-b.y};}
il Complex operator *(Complex a,Complex b) {return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};}
int to[N];
void FFT(Complex *a,int tp)
{
    for(int i=0;i<limit;i++) if(i<to[i]) swap(a[i],a[to[i]]);
    for(int len=1;len<limit;len<<=1)
    {
        Complex Wn={cos(pi/len),sin(pi/len)*tp};
        for(int i=0;i<limit;i+=(len<<1))
        {
            Complex w={1,0};
            for(int j=0;j<len;j++,w=w*Wn)
            {
                Complex x=a[i+j],y=w*a[i+len+j];
                a[i+j]=x+y,a[i+len+j]=x-y;
            }
        }
    }
}
int main()
{
    n=read(),m=read();
    for(int i=0;i<=n;i++) a[i].x=read();
    for(int i=0;i<=m;i++) b[i].x=read();
    int k=0; while(limit<=n+m) limit<<=1,k++;
    for(int i=0;i<limit;i++) to[i]=(to[i>>1]>>1)|((i&1)<<(k-1));
    FFT(a,1),FFT(b,1);
    for(int i=0;i<limit;i++) a[i]=a[i]*b[i];
    FFT(a,-1);
    for(int i=0;i<=n+m;i++) printf("%d ",(int)(a[i].x/limit+0.5));
    return 0;
}