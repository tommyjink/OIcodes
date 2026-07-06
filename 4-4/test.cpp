#include<bits/stdc++.h>
using namespace std;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
struct HH{
    int l,r,cnt;long long q,mx,se,mx_old,tag_add,tag_add_mx,tag_add_old,tag_add_mx_old;
    inline void pushup(const HH x,const HH y){(x.mx>y.mx)?(mx=x.mx,cnt=x.cnt,se=max(x.se,y.mx)):((x.mx<y.mx)?(mx=y.mx,cnt=y.cnt,se=max(y.se,x.mx)):(mx=x.mx,cnt=x.cnt+y.cnt,se=max(x.se,y.se))),q=x.q+y.q,mx_old=max(x.mx_old,y.mx_old);}
    inline void st(const long long add,const long long add_mx,const long long add_old,const long long add_mx_old){q+=add*(r-l+1-cnt)+cnt*add_mx,mx_old=max(mx+add_mx_old,mx_old),mx+=add_mx,se+=se>-1e18?add:0,tag_add_old=max(tag_add_old,tag_add+add_old),tag_add_mx_old=max(tag_add_mx_old,tag_add_mx+add_mx_old),tag_add+=add,tag_add_mx+=add_mx;}
}a[(int)2e6+6];
inline void pushdown(const int x){const long long s=max(a[ls(x)].mx,a[rs(x)].mx);s==a[ls(x)].mx?a[ls(x)].st(a[x].tag_add,a[x].tag_add_mx,a[x].tag_add_old,a[x].tag_add_mx_old):a[ls(x)].st(a[x].tag_add,a[x].tag_add,a[x].tag_add_old,a[x].tag_add_old),s==a[rs(x)].mx?a[rs(x)].st(a[x].tag_add,a[x].tag_add_mx,a[x].tag_add_old,a[x].tag_add_mx_old):a[rs(x)].st(a[x].tag_add,a[x].tag_add,a[x].tag_add_old,a[x].tag_add_old),a[x].tag_add=a[x].tag_add_mx=a[x].tag_add_old=a[x].tag_add_mx_old=0;}
void init(const int x,const int l,const int r){
    if(l==r) cin>>a[x].q,a[x]={l,r,1,a[x].q,a[x].q,(long long)-1e18,a[x].q};
    else init(ls(x),l,(l+r>>1)),init(rs(x),(l+r>>1)+1,r),a[x]={l,r},a[x].pushup(a[ls(x)],a[rs(x)]);
}
void up_add(const int x,const int l,const int r,const int k){
    if(a[x].l>r||a[x].r<l) return;
    if(a[x].l>=l&&a[x].r<=r) a[x].st(k,k,k,k);
    else pushdown(x),up_add(ls(x),l,r,k),up_add(rs(x),l,r,k),a[x].pushup(a[ls(x)],a[rs(x)]);
}
void up_min(const int x,const int l,const int r,const int k){
    if(a[x].l>r||a[x].r<l||a[x].mx<=k) return;
    if(a[x].l>=l&&a[x].r<=r&&a[x].se<k) a[x].q+=a[x].cnt*(k-a[x].mx),a[x].tag_add_mx+=k-a[x].mx,a[x].mx=k;
    else pushdown(x),up_min(ls(x),l,r,k),up_min(rs(x),l,r,k),a[x].pushup(a[ls(x)],a[rs(x)]);
}
long long ask(const int x,const int l,const int r,const bool f){
    if(a[x].l>=l&&a[x].r<=r) return f?a[x].q:a[x].mx;
    pushdown(x);return f?((a[ls(x)].r>=l?ask(ls(x),l,r,f):0)+(a[rs(x)].l<=r?ask(rs(x),l,r,f):0)):max((a[ls(x)].r>=l?ask(ls(x),l,r,f):-1e18),(a[rs(x)].l<=r?ask(rs(x),l,r,f):-1e18));
}
long long ask_old(const int x,const int l,const int r){
    if(a[x].l>=l&&a[x].r<=r) return a[x].mx_old;
    pushdown(x);return max((a[ls(x)].r>=l?ask_old(ls(x),l,r):-1e18),(a[rs(x)].l<=r?ask_old(rs(x),l,r):-1e18));
}
int main(){
    int n,q;
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0),cin>>n>>q,init(1,1,n);
    for(int op,l,r,k;q;q--){
        cin>>op>>l>>r;
        if(op==1) cin>>k,up_add(1,l,r,k);
        else if(op==2) cin>>k,up_min(1,l,r,k);
        else if(op==3) cout<<ask(1,l,r,1)<<"\n";
        else if(op==4) cout<<ask(1,l,r,0)<<"\n";
        else cout<<ask_old(1,l,r)<<"\n";
    }
}