#include<bits/stdc++.h>
using namespace std;
const int N=200;
int mp[N+5][N+5];
struct node
{
    int x,y;
}o;
double sq(double x){return x*x;}
int QuadraticFunction(double x,double a,double h,double c)
{
    return int(a*sq(x-h)+c);
}
int LinearFunction(double x,double a,double b)
{
    return int(x*a+b);
}
int InverseProportionalFunction(double x,double k)
{
    return int(k/x);
}
int big_sin(double x,double k)
{
    return  int(sin(x)*k);
}
void add(int x,int y)
{
    // cout<<x<<" "<<y<<endl;
    if(x>N/2||x<-N/2||y>N/2||y<-N/2)return;
    mp[x+o.x][y+o.y]=1;
}
void init()
{
    o.x=N/2,o.y=N/2;
    for(int i=0;i<=N-1;i++)mp[o.x][i]+=2,mp[i][o.y]+=3;
    // for(int i=-N/2+1;i<=N/2-1;i++)add(i,QuadraticFunction((double)i,0.05,10.0,5.0));
    // for(int i=-N/2+1;i<=N/2-1;i++)add(i,QuadraticFunction((double)i,-0.05,10.0,5.0));
    // for(int i=-N/2+1;i<=N/2-1;i++)add(i,LinearFunction((double)i,3.0,30.0));
    for(int i=-N/2+1;i<=N/2-1;i++)add(i,InverseProportionalFunction((double)i,100.0));
    for(int i=-N/2+1;i<=N/2-1;i++)add(InverseProportionalFunction((double)i,100.0),i);
    // for(int i=-N/2+1;i<=N/2-1;i++)add(i,big_sin((double)i/10,10.0));
}
void print()
{
    for(int j=N-1;j>=0;j--)
    {
        for(int i=0;i<=N-1;i++)
        {
            if(mp[i][j]==2)cout<<"|";
            if(mp[i][j]==3)cout<<"-";
            if(mp[i][j]==5)cout<<"+";
            if(mp[i][j]==1)cout<<"*";
            if(mp[i][j]==0)cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    init();
    print();
    return 0;
}