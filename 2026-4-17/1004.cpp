#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int lg[N];
int cal(int n)
{
    int res=0;
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
            res+=lg[r/l];
    return res;
}
int f(int n){return cal(n)-cal(n-1);}
int g(int n){return f(n*2)-f(n*2-2);}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=2;i<N;i++)
        lg[i]=lg[i/2]+1;
    vector<int> v;
    for(int i=16;i<=500;i+=16)cout<<g(i)<<" ";
    for(int i=1;i<=200;i++)
    {
        cout<<f(i*2)-f(i*2-2)<<" ";
        if(i%4==0)cout<<endl;
        if(i%16==0)v.push_back(f(i*2)-f(i*2-2));
    }
    for(auto i:v)cout<<i<<" ";
    return 0;
}
/*
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 5 
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 6 
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 5 
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 7 
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 5 
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 6 
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 5 
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 8 
1 2 1 3 
1 2 1 4 
1 2 1 3 
1 2 1 5 
1 2 1 3 
1 2 1 4 
1 2 1 3 1 2 1 6 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 5 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1 7 1 2 1 3 1 2 1 4

*/