
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;

int n,p[N],w[N],siz[N],pre[N];
int sum=0;
bool alive[N];
long double ans=0;

struct node {
    int id,w,siz;
    bool operator <(const node &b) const {
        int x=w*b.siz,y=b.w*siz;
        if(x!=y)return x<y;
        return id>b.id;
    }
};

priority_queue<node> q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>p[i]>>w[i];
        sum+=p[i]*w[i];
    }

    if(sum==0) {
        cout<<0<<"\n";
        return 0;
    }

    // 统一变成向左移动
    if(sum<0) {
        reverse(p+1,p+n+1);
        reverse(w+1,w+n+1);
        for(int i=1;i<=n;i++)p[i]=-p[i];
        sum=-sum;
    }

    for(int i=1;i<=n;i++) {
        siz[i]=1;
        pre[i]=i-1;
        alive[i]=true;
        q.push({i,w[i],siz[i]});
    }

    while(sum>0) {
        node t=q.top();
        q.pop();

        int i=t.id;
        if(!alive[i])continue;

        int j=pre[i];

        if(j==0) {
            ans+=(long double)sum/w[i]*siz[i];
            break;
        }

        int d=p[i]-p[j];
        int val=d*w[i];

        if(val>=sum) {
            ans+=(long double)sum/w[i]*siz[i];
            break;
        }

        ans+=(long double)d*siz[i];
        sum-=val;

        alive[j]=false;
        w[i]+=w[j];
        siz[i]+=siz[j];
        p[i]=p[j];
        pre[i]=pre[j];

        q.push({i,w[i],siz[i]});
    }

    cout<<fixed<<setprecision(12)<<ans<<"\n";
    return 0;
}
