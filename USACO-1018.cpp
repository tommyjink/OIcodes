#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,t[N],fac2[N];
struct node{int l,r;}a[N];
bool cmp(node x,node y){return x.l<y.l;}
void add(int x,int d){for(int i=x;i<N;i+=lowbit(i))t[i]+=d;}
int sum(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=t[i];return res;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac2[0]=1;
    for(int i=1;i<N;i++)
        fac2[i]=fac2[i-1]*2%P;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        add(a[i].r,1);
        int k=sum(a[i].l-1);
        ans=(ans+(fac2[k]*fac2[n-i])%P)%P;
    }
    cout<<ans<<endl;
    return 0;
}