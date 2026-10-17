#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define intl long long
#define For(i,a,b) for(intl i=a;i<=b;i++)
#define deo(i,a,b) for(intl i=a;i>=b;i--)
intl read() {
    intl x=0,k=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch == '-') k=-1;ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*k;
}
intl n, k, x[N], ans[2][2];
vector<intl> vec[2];
int main() {
//    freopen("supply.in","r",stdin);
//    freopen("supply.out","w",stdout);
    n = read(), k = read();
    For(i,1,n) x[i] = read();
    For(i,1,n) if(x[i] > 0) vec[0].push_back(x[i]);else vec[1].push_back(-x[i]);
    For(op, 0, 1) if(vec[op].size()) {
        sort(vec[op].begin(), vec[op].end());
        intl sum0 = 0,sum1 = 0, sz = vec[op].size();
        deo(i,sz-1,0) {
            sum0 += vec[op][i]*2;
            if(i-k+1 <= 0) {ans[op][0] = sum0;break;}
            i = i-k+1;
        }
        ans[op][1] = sum0- vec[op][sz-1];
//        cout << op << " " << ans[op][0] <<" " << ans[op][1] << endl;
    }
    printf("%lld\n", min(ans[0][0] + ans[1][1], ans[0][1] + ans[1][0]));
    return 0;
}
/*
7 3
-8 -3 -2 1 4 6 7
5 2
1 3 5 8 13
*/