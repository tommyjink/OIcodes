#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=60,P=1e9+7;
int l,r,k;
struct node
{
    int a[N];
};

node add(const node &x,const node &y,int d)
{
    node res={};
    for(int i=0;i<d;i++)res.a[i]=(x.a[i]+y.a[i])%P;
    return res;
}

node mul(const node &x,const node &y,int d)
{
    node res={};
    for(int i=0;i<d;i++)
        for(int j=0;j<d;j++)
            res.a[(i+j)%d]=(res.a[(i+j)%d]+x.a[i]*y.a[j])%P;
    return res;
}

int calc(int n,int d)
{
    if(!n)return 0;
    node a={},b={},p={},sum={},q={},s={};
    for(int i=0;i<d;i++)
        a.a[i]=(k/d+(i<k%d))%P;
    b=a;
    b.a[0]=(b.a[0]-1+P)%P;
    p.a[0]=1;
    q=a;
    s.a[0]=1;
    while(n)
    {
        if(n&1)
        {
            sum=add(sum,mul(p,s,d),d);
            p=mul(p,q,d);
        }
        // s=add(s,mul(q,s,d),d);
        // q=add(q,s);
        s=add(s,mul(q,s,d),d);
        q=mul(q,q,d);
        n>>=1;
    }
    return mul(b,sum,d).a[0];
}

int solve(int n)
{
    int ans=calc(n,4)+calc(n,5)+calc(n,6);
    ans-=calc(n,12)+calc(n,20)+calc(n,30);
    ans+=calc(n,60);
    return (ans%P+P)%P;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>l>>r>>k;
    cout<<(solve(r)-solve(l-1)+P)%P<<endl;
    return 0;
}
