#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200;
int mp[N][N],num[N];
int p=N/2,q=N/2;
int sq(int x){return x*x;}
int f(int x,int c,int q,int h)
{
    return sq(x-h)/q+c;
}
int f2(int x,int a)
{
    return x/a;
}
signed main()
{
    for(int i=0;i<=N-1;i++)cout<<"_";
    cout<<endl;
    for(int i=1;i<=N-1;i++)
    {
        num[i]=f(i,10,20,100);
        if(num[i]<0)continue;
        if(num[i]>N-1)continue;
        mp[num[i]][i]=1;
    }
    for(int i=1;i<=N-1;i++)
    {
        num[i]=f2(i,5);
        if(num[i]<0)continue;
        if(num[i]>N-1)continue;
        mp[num[i]][i]=1;
    }
    for(int i=N-1;i>=1;i--)
    {
        cout<<"|";
        for(int j=1;j<=N-1;j++)
        {
            if(mp[i][j])cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<=N-1;i++)cout<<"-";
    cout<<endl;
    return 0;
}