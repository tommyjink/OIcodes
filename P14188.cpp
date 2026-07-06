#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define N 1000005
using namespace std;
using ull=unsigned long long;
const int M=1<<20;
const ull INF=(1ULL<<63)-1;
struct node{
	int len;
	ull x,y;
	node(){x=y=len=0;}
	node(ull _x){x=_x,y=0,len=1;}
}t[M<<1];
ull lz[M<<1];
int n,m;
node merge(node a,node b){
	node res;
	res.y=a.y|b.y|(a.x&b.x);
	res.x=(a.x|b.x)&(~res.y);
	res.len=min(a.len+b.len,2LL);
	return res;
}
node apply(ull v,node x){
	if(!x.len) return x;
	if(x.len==1){
		x.x|=v;
		x.y&=(~v);
	}
	else{
		x.x&=(~v);
		x.y|=v;
	}
	return x;
}
void push_up(int p){
	t[p]=merge(t[p<<1],t[p<<1|1]);
}
void give(int p,ull x){
	t[p]=apply(x,t[p]);
	lz[p]|=x;
}
void push_down(int p){
	if(!lz[p]) return ;
	give(p<<1,lz[p]),give(p<<1|1,lz[p]);
	lz[p]=0;
}
void build(){
	for(int i=M-1;i>=1;i--) push_up(i);
}
void change(int p,node x){
	p+=M;
	for(int i=20;i>=1;i--) push_down(p>>i);
	t[p]=x;
	for(int i=1;i<=20;i++) push_up(p>>i);
}
void modify(int l,int r,ull x){
	if(l>=r) return ;
	l+=M,r+=M;
	for(int i=20;i>=1;i--){
		if(((l>>i)<<i)!=l) push_down(l>>i);
		if(((r>>i)<<i)!=r) push_down((r-1)>>i);
	}
	int L=l,R=r;
	while(l<r){
		if(l&1) give(l++,x);
		if(r&1) give(--r,x);
		l>>=1,r>>=1;
	}
	l=L,r=R;
	for(int i=1;i<=20;i++){
		if(((l>>i)<<i)!=l) push_up(l>>i);
		if(((r>>i)<<i)!=r) push_up((r-1)>>i);
	}
}
node query(int l,int r){
	if(l>=r) return node();
	l+=M,r+=M;
	for(int i=20;i>=1;i--){
		if(((l>>i)<<i)!=l) push_down(l>>i);
		if(((r>>i)<<i)!=r) push_down((r-1)>>i);
	}
	node L,R;
	while(l<r){
		if(l&1) L=merge(L,t[l++]);
		if(r&1) R=merge(t[--r],R);
		l>>=1,r>>=1;
	}
	return merge(L,R);
}
bool check(node x,int i){
	return ((x.x|x.y)>>i)&1;
}
node findpos(int l,int i){
	l+=M;
	node now;
	while(1){
		while(!(l&1)) l>>=1;
		if(check(merge(now,t[l]),i)){
			while(l<M){
				push_down(l);
				if(check(merge(now,t[l<<1]),i)) l<<=1;
				else now=merge(now,t[l<<1]),l=l<<1|1;
			}
			return t[l];
		}
		now=merge(now,t[l]);
		l++;
		if((l&-l)==l) return node();
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		ull x; cin>>x;
		x^=INF;
		t[M+i]=node(x);
	}
	build();
	while(m--){
		int op; cin>>op;
		if(op==1){
			int l,r; ull x;
			cin>>l>>r>>x; l--;
			x^=INF;
			modify(l,r,x);
		}
		else if(op==2){
			int p; ull x;
			cin>>p>>x; p--;
			x^=INF;
			change(p,node(x));
		}
		else{
			int l,r;
			cin>>l>>r; l--;
			node res=query(l,r);
			ull ans=(~(res.x|res.y))&INF;
			if(res.x){
				int i=63-__builtin_clzll(res.x);
				node tmp=findpos(l,i);
				ans|=(res.x&tmp.x);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
