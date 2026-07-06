#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define bt bitset<N>
using namespace std;
const int N=2005;
int n,m,q;
bt p[N];

void insert(bt x)
{
    
    for(int i=m-1;i>=0;i--) 
    {
        if(!x[i])continue;
        if(!p[i].count()){p[i]=x;break;}
        x^=p[i];
    }
}

void init()
{
    
    for(int i=0;i<m;i++) 
    {
        if(!p[i].count())continue;
        for(int j=i-1;j>=0;j--)
            if(p[i][j])p[i]^=p[j]; 
    }
}

bt query(bt x)
{
    for(int i=m-1; i>=0; i--) {
        if(x[i] && p[i].count()) {
            x ^= p[i];
        }
    }
    for(int i=m-1; i>=0; i--) {
        if((x << (N - 1 - i)).none()) {
            break; 
        }
        if(p[i].count()) {
            x ^= p[i];
        }
    }
    return x;
}

bt input()
{
    string s;cin>>s;
    bt now;
    for(int j=0;j<m;j++)now[m-j-1]=s[j]-'0';
    return now;
}

void output(bt x)
{
    for(int i=m-1;i>=0;i--)cout<<x[i];
    cout<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        insert(input());
    
    init(); 
    
    while(q--)
    {
        output(query(input()));
    }
    return 0;
}