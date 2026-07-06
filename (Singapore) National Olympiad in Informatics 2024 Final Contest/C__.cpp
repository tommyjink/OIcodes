#include "toxic.h"
#include<bits/stdc++.h>
using namespace std;
const int N=1010,B=31;
int a[N],d[N],p[N],T;
bool chk(vector<int> v)
{
    vector<int> res=query_machine(v);
    return res.back()<(int)v.size();
}
int getT(int n)
{
    vector<int> v;
    for(int i=1;i<n;i++)v.push_back(i);
    while(v.size()>1)
    {
        int mid=v.size()/2;
        vector<int> q;
        q.push_back(0);
        for(int i=0;i<mid;i++)q.push_back(v[i]);
        if(chk(q))
        {
            while(v.size()>mid)v.pop_back();
        }
        else
        {
            vector<int> nw;
            for(int i=mid;i<(int)v.size();i++)nw.push_back(v[i]);
            v=nw;
        }
    }
    int x=v[0];
    vector<int> res=query_machine({0,x,0});
    if(res.back()==2)return 0;
    return x;
}
void sol(vector<int> v)
{
    vector<int> q,res;
    for(int i=0;i<=50;i++)d[i]=0;
    q.push_back(T);
    for(int i=0;i<(int)v.size();i++)
    {
        for(int j=1;j<=i*2+1;j++)q.push_back(v[i]);
        q.push_back(T);
    }
    // for(auto x:q)cerr<<x<<" ";cerr<<endl;
    res=query_machine(q);
    int now=q.size();
    for(int i=0;i<(int)res.size();i++)
    {
        d[i]=now-res[i];
        now=res[i];
    }
    // for(int i=0;i<(int)res.size();i++)cerr<<d[i]<<" ";cerr<<endl;
    for(int i=0;i<(int)v.size();i++)p[v[i]]=(d[i]&1?1:0);
}
void determine_type(int n)
{
    T=getT(n);
    vector<char> ret(n,'T');
    for(int l=0;l<n;l+=B)
    {
        vector<int> v;
        for(int i=l;i<n&&i<l+B;i++)
            if(i!=T)v.push_back(i);
        if(v.size())sol(v);
    }
    for(int i=0;i<n;i++)
        if(p[i])ret[i]='R';
    ret[T]='T';
    // for(auto c:ret)cerr<<c;cerr<<endl;
    answer_type(ret);
}
