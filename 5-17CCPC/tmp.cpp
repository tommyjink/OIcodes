#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const double eps=1e-7;
struct node{
    int x,y;
};
node d[N];
int n,a,b,c;
double calc(double v){
    if(a==0){
        double y=(double)(-c)/b;
        double res=0;
        for(int i=1;i<=n;i++){
            double dx=v-d[i].x;
            double dy=y-d[i].y;
            res=max(res,dx*dx+dy*dy);
        }
        return res;
    }else if(b==0){
        double x=(double)(-c)/a;
        double res=0;
        for(int i=1;i<=n;i++){
            double dx=x-d[i].x;
            double dy=v-d[i].y;
            res=max(res,dx*dx+dy*dy);
        }
        return res;
    }else{
        double y=(double)(-c-a*v)/b;
        double res=0;
        for(int i=1;i<=n;i++){
            double dx=v-d[i].x;
            double dy=y-d[i].y;
            res=max(res,dx*dx+dy*dy);
        }
        return res;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d[i].x>>d[i].y;
    }
    cin>>a>>b>>c;
    double l=-1e5,r=1e5;
    double ans=1e18;
    while(r-l>eps){
        double x1=l+(r-l)/3;
        double x2=r-(r-l)/3;
        double f1=calc(x1);
        double f2=calc(x2);
        ans=min(ans,f1);
        ans=min(ans,f2);
        if(f1>f2)l=x1;
        else r=x2;
    }
    ans=sqrt(ans);
    cout<<fixed<<setprecision(10)<<ans<<'\n';
}
int main(){
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}