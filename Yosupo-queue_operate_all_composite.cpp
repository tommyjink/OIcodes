#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10,P=998244353;
int q,mul=1,add=0;
deque<pii> dq;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        x=x*x%P;
        y>>=1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==0)
        {
            int a,b;
            cin>>a>>b;
            add=add*a%P;
            mul=mul*a%P;
            add=(add+b)%P;
            dq.push_back({a,b});
        }
        if(op==1)
        {
            int a=dq.front().first;
            int b=dq.front().second;
            mul=mul*qpow(a,P-2)%P;
            add=((add-b*mul%P)%P+P)%P;
            dq.pop_front();
        }
        if(op==2)
        {
            int x;cin>>x;
            cout<<(mul*x%P+add)%P<<endl;
        }
    }
    return 0;
}