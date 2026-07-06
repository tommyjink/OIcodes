#include<bits/stdc++.h>
using namespace std;

const int N=400000+5;
const long long INF=0x3f3f3f3f3f3f3f3fLL;

inline long long Min(long long a,long long b){return a<b?a:b;}
inline long long Max(long long a,long long b){return a>b?a:b;}

int n,k;
int w[N];
long long s[N];
int x[N],y[N],d[N],pre[N],nxt[N],hh[N],tt[N],ii[N],qu[N];
long long dp[N];

int Cross(int i,int j){
    int l=-1,r=k-y[j]+1;
    while(r-l>1){
        int mid=(l+r)/2;
        if(dp[i]-s[y[i]+mid]>dp[j]-s[y[j]+mid])r=mid;
        else l=mid;
    }
    return l;
}

void Merge(int i,int j){
    int u,v,dd;
    u=tt[i],v=hh[j];
    while(1){
        dd=Cross(u,v);
        if(u!=hh[i]&&Cross(pre[u],u)<=dd)u=pre[u];
        else if(v!=tt[j]&&Cross(v,nxt[v])>=dd)v=nxt[v];
        else{
            nxt[u]=v;
            pre[v]=u;
            break;
        }
    }
    hh[j]=hh[i];
}

long long Query(int i,int dd){
    while(hh[i]!=tt[i]&&Cross(hh[i],nxt[hh[i]])>=dd)hh[i]=nxt[hh[i]];
    return dp[hh[i]]-s[y[hh[i]]+dd];
}

void Dc(int il,int ir,int jl,int jr){
    int i,i_,j,dd;
    long long z,z_;
    if(jl>jr)return;
    j=(jl+jr)/2;
    dd=k-y[j];
    z_=-INF;
    for(i_=i=max(il,ii[j]+1);i<=ir&&i<=j;i++)
        if(dp[i]!=-INF){
            z=dp[i]-s[y[i]+dd];
            if(z_<z)z_=z,i_=i;
        }
    if(i_==il-1)i_=il;
    if(ii[j]>=0)z_=Max(z_,dp[ii[j]]-s[x[ii[j]]]);
    else z_=Max(z_,-s[dd]);
    z_+=s[k];
    Dc(il,i_,jl,j-1);
    printf("%lld ",z_);
    Dc(i_,ir,j+1,jr);
}

int main(){
    static int a[N];
    int cnt,h,i,i_,j,cur,yy;

    scanf("%d",&n);
    memset(ii,-1,n*sizeof *ii);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]--;
        if(a[i]>=0)ii[a[i]]=i;
    }
    for(cur=0;cur<n;cur++)scanf("%d",&w[cur]);

    k=0;
    for(cur=0;cur<n;cur++){
        if((i=ii[cur])!=-1)x[i]=k;
        else s[k+1]=s[k]+w[cur],k++;
    }

    for(i=0;i<n;i++)pre[i]=nxt[i]=-1,hh[i]=tt[i]=i;

    yy=0,cur=-1,cnt=0,h=0;
    for(j=0;j<n;j++){
        if(a[j]<0)yy++;
        y[j]=yy;
        d[j]=x[j]-y[j];
        cur=max(cur,a[j]);
        if(a[j]==cur&&d[j]>=0){
            i_=-1;
            while(cnt&&d[i=qu[cnt-1]]<d[j]){
                if(i_==-1)i_=i;
                else Merge(i,i_);
                cnt--;
            }
            dp[j]=cnt?dp[i]-s[x[i]]:-s[d[j]];
            if(i_!=-1)dp[j]=Max(dp[j],Query(i_,d[j]));
            dp[j]+=s[x[j]]+w[a[j]];
            if(i_!=-1)Merge(i_,j);
            qu[cnt++]=j;
        }
        else dp[j]=-INF;

        h=Min(h,cnt);
        while(h<cnt&&d[qu[h]]>=k-yy)h++;
        ii[j]=(h==0?-1:qu[h-1]);
    }

    Dc(0,n-1,0,n-1);
    puts("");
    return 0;
}
