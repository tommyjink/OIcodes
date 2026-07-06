#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=6e5+10,P=998244353;
int n,q,ct[70],t[70],fac[N],ifac[N],p2[N],u[N][70];
inline int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
void init(){
    p2[0]=fac[0]=1;
    for(int i=1;i<N;i++){
        p2[i]=p2[i-1]*2%P;
        fac[i]=fac[i-1]*i%P;
    }
    ifac[N-1]=qpow(fac[N-1],P-2);
    for(int i=N-2;i>=0;i--)ifac[i]=ifac[i+1]*(i+1)%P;
    u[0][0]=1;
    for(int i=1;i<N;i++){
        u[i][0]=p2[i];
        for(int j=1;j<70;j++)
            u[i][j]=(u[i-1][j-1]+u[i-1][j])%P;
    }
}
inline int C(int n,int r){
    if(r<0||r>n)return 0;
    return fac[n]*ifac[r]%P*ifac[n-r]%P;
}
void solve(int x){
    int sm[70]={0},ans=0,pre=1,cur=0;
    sm[0]=ct[0];
    for(int i=1;i<=60;i++)sm[i]=sm[i-1]+ct[i];
    for(int i=60;i>=0;i--){
        int now=0;
        while(now<ct[i]){
            int val=(cur>i)?0:(1ll<<i)>>cur;
            if(val>0&&val>(x>>1)&&val<x){
                x-=val;cur++;now++;
            }else break;
        }
        if(now<ct[i]){
            int val=(cur>i)?0:(1ll<<i)>>cur;
            if(val>=x){
                int ways=(i>0)?p2[sm[i-1]]:1;
                ans=(ans+pre*ways%P*u[ct[i]][now+1])%P;
            }
        }
        pre=pre*C(ct[i],now)%P;
        if(!pre)break;
    }
    if(!x)ans=(ans+pre)%P;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ct[x]++;
    }
    while(q--){
        int op,x;
        cin>>op>>x;
        if(op==1)ct[x]++;
        else if(op==2)ct[x]--;
        else solve(x);
    }
    return 0;
}



// #include<bits/stdc++.h>
// #define int long long
// #define endl "\n"
// #define lowbit(x) (x&(-x))
// using namespace std;
// const int N=1e6+10,P=998244353;
// int n,q,fac[N],t[100];
// void add(int x,int d)
// {
//     x++;
//     for(int i=x;i<100;i+=lowbit(i))
//         t[i]+=d;
// }
// inline int query(int x)
// {
//     x++;
//     if(x<=0)return 0;
//     int res=0;
//     for(int i=x;i;i-=lowbit(i))
//         res+=t[i];
//     return res;
// }
// inline int sum(int l,int r)
// {
//     return query(r)-query(l-1);
// }
// void solve(int x)
// {
//     int v[100]={0},m=0,ans=1;
//     for(int i=60;i>=0;i--)
//         if(x&(1ll<<i))v[++m]=i+m;
//     int tmp=1;
//     for(int i=1;i<=m;i++)
//     {
//         int now=v[i];
//         ans=(ans+(sum(now+1,99))*fac[sum(now+1,99)-1]%P)%P*tmp%P;
//         tmp=tmp*(sum(now,now))%P;
//         add(now,-1);
//         cout<<v[i]<<" "<<tmp<<" "<<ans<<endl;
//         if(sum(now,now)<0)break;
//     }
//     ans=ans*fac[sum(0,99)]*tmp%P;
//     cout<<ans<<endl;
// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     fac[0]=1;
//     for(int i=1;i<N;i++)
//         fac[i]=fac[i-1]*2%P;
//     cin>>n>>q;
//     for(int i=1;i<=n;i++)
//     {
//         int x;
//         cin>>x;
//         add(x,1);
//     }
//     while(q--)
//     {
//         int op,x;
//         cin>>op>>x;
//         if(op==1)add(x,1);
//         else if(op==2)add(x,-1);
//         else solve(x);
//     }
//     return 0;
// }