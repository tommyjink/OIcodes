#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=5e5+10,B=16,M=N/B+2;
int n,q,h[N],s[N],top,lg[M];
struct rmq
{
    int a[N],pre[N],suf[N],f[16][M];
    void build()
    {
        for(int l=1;l<=n;l+=B){
            int r=min(n,l+B-1);
            pre[l]=a[l];
            suf[r]=a[r];
            for(int i=l+1;i<=r;i++)pre[i]=max(pre[i-1],a[i]);
            for(int i=r-1;i>=l;i--)suf[i]=max(suf[i+1],a[i]);
            f[0][(l-1)/B]=pre[r];
        }
        int m=(n+B-1)/B;
        for(int j=1;(1<<j)<=m;j++){
            for(int i=0;i+(1<<j)<=m;i++)f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
        }
    }
    int query(int l,int r)
    {
        if(l>r)return 0;
        int x=(l-1)/B,y=(r-1)/B;
        if(x==y){
            int res=a[l];
            for(int i=l+1;i<=r;i++)res=max(res,a[i]);
            return res;
        }
        int res=max(suf[l],pre[r]);
        if(x+1<y){
            int k=lg[y-x-1];
            res=max(res,max(f[k][x+1],f[k][y-(1<<k)]));
        }
        return res;
    }
}fst,lst,to,fr;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>h[i];
        fst.a[i]=h[i]*N+N-i;
        lst.a[i]=h[i]*N+i;
    }
    for(int i=n;i>=1;i--){
        while(top&&h[s[top]]<h[i])top--;
        if(top&&h[s[top]]==h[i])to.a[i]=(s[top]-i)*h[i];
        else s[++top]=i;
    }
    top=0;
    for(int i=1;i<=n;i++){
        while(top&&h[s[top]]<h[i])top--;
        if(top&&h[s[top]]==h[i])fr.a[i]=(i-s[top])*h[i];
        else s[++top]=i;
    }
    for(int i=2;i<=(n+B-1)/B;i++)lg[i]=lg[i/2]+1;
    fst.build();
    lst.build();
    to.build();
    fr.build();
    int l,r,z=0,ans=0;
    cin>>l>>r;
    for(int i=1;i<=q;i++){
        int a=N-fst.query(l,r)%N,b=lst.query(l,r)%N;
        z=max({(b-a)*h[a],to.query(l,a-1),fr.query(b+1,r)});
        ans^=z+i;
        int x=(l+37*z)%n+1,y=(l+r+53*z)%n+1;
        l=min(x,y);
        r=max(x,y);
    }
    cout<<ans<<endl;
    return 0;
}
