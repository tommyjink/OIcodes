#include<bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int n,k,w[MAXN],c[MAXN],siz[MAXN],son[MAXN],dep[MAXN],top[MAXN],Fa[MAXN],dfn[MAXN],chk[MAXN];
int udf[MAXN],Ans,idx,nxt[MAXN],idfn[MAXN];
vector<int> tr[MAXN],cp[MAXN];



inline bool cmp( int x , int y ){ return dfn[x] < dfn[y]; }

void dfs( int x , int fa ){
	siz[x] = 1,son[x] = 0,Fa[x] = fa;
	dep[x] = dep[fa] + 1,dfn[x] = ++idx,idfn[idx] = x;
	for( int v : tr[x] ){
		if( v == fa ) continue;
		dfs( v , x ),siz[x] += siz[v];
		if( siz[v] > siz[son[x]] ) son[x] = v;
	}
}

void dfs2( int x ){
	if( !top[x] ) top[x] = x;
	if( son[x] ){ top[son[x]] = top[x]; dfs2( son[x] ); }
	for( int v : tr[x] ) if( v != son[x] && v != Fa[x] ) dfs2( v );
}

inline int Lca( int u , int v ){
	while( top[u] != top[v] ){
		if( dep[top[u]] < dep[top[v]] ) swap( u , v );
		u = Fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}


void Calc( int x ){
	int uc = 1;
	for( int v : tr[x] ){
		if( v == Fa[x] ) continue;
		Calc( v ),uc = uc && udf[v];
	}
	if( uc && !c[x] ) udf[x] = 1;
	else{
		if( !c[x] ){
			if( chk[x] < 0 ) c[x] = -chk[x],Ans += w[x];
			else if( chk[x] > 0 ) c[x] = chk[x];
			else c[x] = c[idfn[nxt[dfn[x]]]];
		}
		else if( chk[x] < 0 || ( chk[x] > 0 && c[x] != chk[x] ) ) Ans += w[x];
	}
}


void Print( int x ){
	if( udf[x] ) c[x] = c[Fa[x]];
	for( int v : tr[x] ){
		if( v == Fa[x] ) continue;
		Print( v );
	}
}

inline void solve(){
	scanf("%lld%lld",&n,&k); Ans = 0;
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&w[i]);
	for( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&c[i]),cp[c[i]].emplace_back( i );
	for( int i = 1 ; i < n ; i ++ ){
		int u,v; scanf("%lld%lld",&u,&v);
		tr[u].emplace_back( v ),tr[v].emplace_back( u );
	} idx = 0,dfs( 1 , 0 ),dfs2( 1 );
	c[0] = 1;
	for( int i = n , lst = n + 1 ; i >= 1 ; i -- ){ if( c[idfn[i]] ) lst = i; nxt[i] = lst; }
	for( int i = 1 ; i <= n ; i ++ ) chk[i] = 0;
	for( int c = 1 ; c <= k ; c ++ ){
		sort( cp[c].begin() , cp[c].end() , cmp );
		
		int siz = cp[c].size();
		for( int i = 0 ; i < siz - 1 ; i ++ ){
			int u = Lca( cp[c][i] , cp[c][i + 1] );
			if( u == cp[c][i] || u == cp[c][i + 1] ) continue;
			if( chk[u] < 0 ) continue;
			if( chk[u] > 0 && chk[u] != c ) chk[u] = -chk[u]; else chk[u] = c;
		}
	}
	Calc( 1 ),Print( 1 );
	printf("%lld\n",Ans);
	for( int i = 1 ; i <= n ; i ++ ) printf("%lld ",c[i]); puts("");
	for( int i = 1 ; i <= n ; i ++ ) tr[i].clear(),chk[i] = dfn[i] = siz[i] = son[i] = top[i] = dep[i] = Fa[i] = idfn[i] = udf[i] = nxt[i] = 0;
	for( int i = 0 ; i <= k ; i ++ ) cp[i].clear();
}

signed main(){
	int testcase; scanf("%lld",&testcase);
	while( testcase -- ) solve();
	return 0;
}
