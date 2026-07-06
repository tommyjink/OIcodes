#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353;
int n,m,q;
inline int cal(int x,int y)
{
    if((x+y)&1)return 0;
    return ((x-1+P)*m%P+y)%P;
}
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
    cin>>n>>m>>q;
    int inv2=qpow(2,P-2);
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int l1=b-a+1,l2=d-c+1;
        int suma=0,ca=0,p1=c,p2=d;
        while(!cal(a,p1))p1++;
        while(!cal(a,p2))p2--;
        if(p1<=p2)
            ca=(p2-p1)/2+1,
            suma=(cal(a,p1)+cal(a,p2))%P*ca%P*inv2%P;
        if(l1==1)
        {
            cout<<suma<<endl;
            continue;
        }
        p1=c,p2=d;
        int sumb=0,cb=0;
        while(!cal(a+1,p1))p1++;
        while(!cal(a+1,p2))p2--;
        if(p1<=p2)
            cb=(p2-p1)/2+1,
            sumb=(cal(a+1,p1)+cal(a+1,p2))%P*cb%P*inv2%P;
        int cnta=(b-a)/2+1;
        int cntb=l1-cnta;
        int da=ca*m%P*2%P,db=cb*m%P*2%P;
        int ansa=(suma+(suma+(cnta-1)*da%P)%P)%P*cnta%P*inv2;
        int ansb=(sumb+(sumb+(cntb-1)*db%P)%P)%P*cntb%P*inv2;
        // printf("ansa:%lld,ansb%lld,cnta:%lld,cntb:%lld,ca:%lld,cb:%lld,suma:%lld,sumb:%lld,da:%lld,db:%lld\n",ansa,ansb,cnta,cntb,ca,cb,suma,sumb,da,db);
        cout<<(ansa+ansb)%P<<endl;
    }
    return 0;
}