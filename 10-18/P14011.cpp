
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 406;
const int S = N * N + 5;
ll n, q, a[N], b[N], f[2][S], g[S], h[S], sa, sb;
ll win, lose, draw;
int main(){
	scanf("%lld", &n);
	for(ll i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &b[i]), sa += a[i];
	memset(f, 0xc0, sizeof(f)); f[0][0] = 0;
	for(ll i = 1; i <= n; i++){
		f[i&1][0] = (sb += b[i]);
		for(ll j = 0; j <= sa; j++){
			f[i&1][j] = f[(i&1)^1][j] + b[i];
			if(a[i] <= j) f[i&1][j] = max(f[i&1][j], f[(i&1)^1][j - a[i]]);
		}
	}
	for(ll i = 0; i <= sa; i++) g[i] = i + f[n&1][i];
	for(ll i = sa; i >= 0; i--){
		h[i] = max(h[i+1], f[n&1][i]);
		g[i] = max(g[i+1], g[i]);
	}
	scanf("%lld", &q);
	while(q--){
		ll x, y; scanf("%lld%lld", &x, &y);
		ll w = 0, d = 0;
		if(x - f[n&1][0] <= 0) d++;
		if(h[y+1] > x) w++;
		else{
			if(h[y+1] == x) d++;
			if(g[y+1] > x + y) w++;
			else if(g[y+1] == x + y) d++;
		}
		if(w) win++;
		else if(d) draw++;
		else lose++;
	}
	printf("%lld %lld %lld\n", win, draw, lose);
	return 0;
}
