#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define intl int
#define inf (N)
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
    intl x=0,k=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') k=-1;ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*k;
}
intl n, x[N], y[N], f[N], head[N], nxt[N];
struct BIT{
    #define low(x) ((x)&-(x))
    intl tr[N];
    void add(intl x, intl v, intl sz) {
        for(;x<=sz;x += low(x)) tr[x] = min(tr[x], v);
    }
    intl ask(intl x) {
        intl ans = inf;
        for(;x;x-=low(x)) ans = min(ans,tr[x]);
        return ans;
    }
}bit;
vector<intl> vec[N]; 
void cdq(intl l, intl r) {
//    cout << l << " "<< r<<endl;
    if(l == r) {
        if(l > 0) f[l] = min(f[l], f[l-1] + 1);
        return;
    }
    intl mid = (l + r) >> 1;
    cdq(l, mid);
    intl mnx = *min_element(x+l,x+r+1), mxx = *max_element(x+l,x+r+1), mny = *min_element(y+l,y+r+1), mxy = *max_element(y+l,y+r+1);
//    cout << l << " " << r <<" " << mnx << " " << mxx << " " << mny <<" " << mxy <<endl;
    intl sx = mxx - mnx + 1, sy = mxy - mny + 1;
    For(i,0,sx) vec[i].clear();
    For(i,0,sy) bit.tr[i] = inf;
    For(i, l, r) vec[x[i] - mnx].push_back(i);
    For(b, 0, sx) for(auto p:vec[b]) {
//        cout << l << " " << r << " " << p << " " << endl;
        if(p <= mid) bit.add(y[p] - mny + 1, f[p], sy);
        else f[p] = min(bit.ask(y[p] - mny + 1), f[p]);
//        if(l <= 3 && 3 <= r) cout << f[3] <<endl;
    }
    cdq(mid + 1, r);
}
int main() {
    n = read();
    string s;cin >> s;
    For(i, 1, n) {
        intl mask = s[i-1] - '0';
        intl a = (mask >> 2) & 1, b = (mask >> 1) & 1, c = mask & 1;
        x[i] = x[i-1] + a - b,    y[i] = y[i-1] + a - c;
    }
    For(i, 0, n) f[i] = inf;
    f[0] = 0;
//    For(i, 0, n) cout << x[i] << " \n"[i == n];
//    For(i, 0, n) cout << y[i] << " \n"[i == n];
    cdq(0, n);
//    For(i,0,n) cout << f[i] << " \n"[i == n]; 
    printf("%d\n", n - f[n]);
    return 0;
}