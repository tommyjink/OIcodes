#include<bits/stdc++.h>

namespace GN_TAC1A3C_51TL {
	// :: -std=c++14 -O2 -Wall
	// GN-TAC 1A3/C-51 TL "Super Table 3"
	namespace PzSprG_DSsLec_250347_1D {
		//Tag: RhPrh 14039K(P,c,RP-3E2)
		std::string Set_Nsolution = "-1";
		#define NO_SOLUTION {cout << Set_Nsolution;return 0;}

		namespace mathematicsh{
			inline int gcd(int a,int b){return (b==0?a:gcd(b,a%b));}
			inline bool isprime(int n){if(n<2)return 0;
				for(int i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}
			inline int int_sqr(int x){return x*x;}
			inline double double_sqr(double x){return x*x;}
			inline double Eulid_distance(double x1,double y1,double x2,double y2){
				return sqrt(double_sqr(x1-x2)+double_sqr(y1-y2));}
			inline int Manhattan_distance(int x1,int y1,int x2,int y2){
				return abs(x1-x2)+abs(y1-y2);}
			inline int qpow(int x,int y,int mod=1e9+7){
				int ans=1,base=x;
				while(y>0){if(y&1)ans*=base,ans%=mod;
					base*=base;base%=mod;y>>=1;}
				return ans%mod;}
			inline double Pythagoras(double s1,double s2){return sqrt(double_sqr(s1)+double_sqr(s2));}
		}
		//// ---------- ---------- ---------- ---------- ---------- ---------- ////
		namespace IO{
			inline bool isnum(char ch){return ch>='0'&&ch<='9';}
			inline int read(){int x=0,f=1;char ch=getchar();
				while (!isnum(ch)){if (ch=='-') f=-1;ch=getchar();}
				while (isnum(ch)){x=x*10+ch-48;ch=getchar();}return x*f;}
			inline void out(int x,char ch){if(x<0){putchar('-');x=-x;}
			    if(x>9)out(x/10,'/');putchar(x%10+'0');
			    if(ch=='l')putchar('\n');if(ch=='s')putchar(' ');}}
		//// ---------- ---------- ---------- ---------- ---------- ---------- ////
		namespace Usual{inline bool igcmp(int a,int b){return a>b;}inline bool ilcmp(int a,int b){return a<b;}}
		//// ---------- ---------- ---------- ---------- ---------- ---------- ////
		namespace Debug{
			#define err() cout<<"err "<<__LINE__<<endl,exit(0)
			#define pot(args...) \
			GPT(#args),cout<<"  Line "<<__LINE__<<"\t: ", \
			PPT(args),cout<<"\n\n"
			void PPT(){}
			template<typename TYPE,typename... TYPES>
			void PPT(const TYPE& x,const TYPES&... y){std::cout<<x<<' ';PPT(y...);}
			void GPT(std::string nam){std::cout<<std::setw(29)<<nam;}}
		//// ---------- ---------- ---------- ---------- ---------- ---------- ////
		using namespace std;
		using namespace mathematicsh;
		using namespace IO;
		using namespace Usual;
		using namespace Debug;

		//// wait for addition ////
	}

	using namespace PzSprG_DSsLec_250347_1D;
	//// ---------- ---------- ---------- ---------- ---------- ---------- ////
	namespace DATA_STRUCTURE_1A1 {
		struct Segment_Tree {
			// TC17A4, late
			#define lson p<<1
			#define rson p<< 1|1
			int siize,infni;
			vector<int> sum,add,mul,cov,mxi,mni;vector<bool> ifcov;
			Segment_Tree(){siize=0;}
			Segment_Tree(int n,int inf=1e9+7){siize=n;infni=inf;
				sum.resize((n+2)<<2);add.resize((n+2)<<2);
				mul.resize((n+2)<<2);cov.resize((n+2)<<2);
				mxi.resize((n+2)<<2);mni.resize((n+2)<<2);
				ifcov.resize((n+2)<<2);}
			void pushup(int p){sum[p]=sum[lson]+sum[rson];
				mxi[p]=max(mxi[lson],mxi[rson]);mni[p]=min(mni[lson],mni[rson]);}
			void pushdown(int p,int l,int r){
				int mid=l+((r-l)>>1);
				if(ifcov[p]){add[lson]=add[rson]=0;mul[lson]=mul[rson]=1;
					cov[lson]=cov[rson]=cov[p];ifcov[lson]=ifcov[rson]=1;
					sum[lson]=(mid-l+1)*cov[p];sum[rson]=(r-mid)*cov[p];
					mxi[lson]=mxi[rson]=mni[lson]=mni[rson]=cov[p];ifcov[p]=0;cov[p]=0;}
				if(mul[p]!=1){sum[lson]*=mul[p];sum[rson]*=mul[p];
					mxi[lson]*=mul[p];mxi[rson]*=mul[p];mni[lson]*=mul[p];mni[rson]*=mul[p];
					mul[lson]*=mul[p];mul[rson]*=mul[p];add[lson]*=mul[p];add[rson]*=mul[p];mul[p]=1;}
				if(add[p]){sum[lson]+=add[p]*(mid-l+1);sum[rson]+=add[p]*(r-mid);
					mxi[lson]+=add[p];mxi[rson]+=add[p];mni[lson]+=add[p];mni[rson]+=add[p];
					add[lson]+=add[p];add[rson]+=add[p];add[p]=0;}}
			void build_sequence(int r,int a[],int p=1,int l=1){
				add[p]=0;mul[p]=1;cov[p]=ifcov[p]=0;if(l==r){sum[p]=mni[p]=mxi[p]=a[l];return;}
				int mid=l+((r-l)>>1);build_sequence(mid,a,lson,l);build_sequence(r,a,rson,mid+1);pushup(p);}
			void build_number(int r,int num,int p=1,int l=1){
				add[p]=0;mul[p]=1;cov[p]=ifcov[p]=0;if(l==r){sum[p]=mni[p]=mxi[p]=num;return;}
				int mid=l+((r-l)>>1);build_number(mid,num,lson,l);build_number(r,num,rson,mid+1);pushup(p);}
			void build_empty(int r,int p=1,int l=1){
				add[p]=0;mul[p]=1;cov[p]=ifcov[p]=0;if(l==r){sum[p]=0;mni[p]=infni;mxi[p]=-infni;return;}
				int mid=l+((r-l)>>1);build_empty(mid,lson,l);build_empty(r,rson,mid+1);pushup(p);}
			void op_plus(int r,int x,int y,int num,int p=1,int l=1){if(x<=l&&r<=y){
				if(ifcov[p]){cov[p] += num;sum[p]=cov[p]*(r-l+1);mxi[p]=mni[p]=cov[p];return;}
					sum[p]+=(r-l+1)*num;mxi[p]+=num;mni[p]+=num;add[p]+=num;return;}
				int mid=l+((r-l)>>1);pushdown(p,l,r);
				if(x<=mid)op_plus(mid,x,y,num,lson,l);if(y>mid)op_plus(r,x,y,num,rson,mid+1);pushup(p);}
			void op_cover(int r,int x,int y,int num,int p=1,int l=1){
				if(x<=l&&r<=y){
					add[p]=0;mul[p]=1;ifcov[p]=1;cov[p]=num;mxi[p]=mni[p]=num;sum[p]=num*(r-l+1);return ;}
				int mid=l+((r-l)>>1);pushdown(p,l,r);
				if(x<=mid)op_cover(mid,x,y,num,lson,l);if(y>mid)op_cover(r,x,y,num,rson,mid+1);pushup(p);}
			void op_multiply(int r,int x,int y,int num,int p=1,int l=1){if(x<=l&&r<=y) {
				if(ifcov[p]){cov[p]*=num;sum[p]=cov[p]*(r-l+1);mxi[p]=mni[p]=cov[p];return;}
					add[p]*=num;mul[p]*=num;mxi[p]*=num;mni[p]*=num;sum[p]*=num;return;}
				int mid=l+((r-l)>>1);pushdown(p,l,r);
				if(x<=mid)op_multiply(mid,x,y,num,lson,l);if(y>mid)op_multiply(r,x,y,num,rson,mid+1);pushup(p);}
			int query_sum(int r,int x,int y,int p=1,int l=1){
				if(x<=l&&r<=y)return sum[p];int mid=l+((r-l)>>1),res=0;pushdown(p,l,r);
				if(x<=mid)res+=query_sum(mid,x,y,lson,l);if(y>mid)res+=query_sum(r,x,y,rson,mid+1);return res;}
			int query_max(int r,int x,int y,int p=1,int l=1){
				if(x<=l&&r<=y)return mxi[p];int mid=l+((r-l)>>1),res=-infni;pushdown(p,l,r);
				if(x<=mid)res=max(res,query_max(mid,x,y,lson,l));if(y>mid)res=max(res,query_max(r,x,y,rson,mid+1));
				return res;}
			int query_min(int r,int x,int y,int p=1,int l=1){
				if(x<=l&&r<=y)return mni[p];int mid=l+((r-l)>>1),res=infni;pushdown(p,l,r);
				if(x<=mid)res=min(res,query_min(mid,x,y,lson,l));if(y>mid)res=min(res,query_min(r,x,y,rson,mid+1));
				return res;}
		};
	}

	using namespace DATA_STRUCTURE_1A1;
	//// ---------- ---------- ---------- ---------- ---------- ---------- ////
	namespace Easyuse{
		#define mdis Manhattan_distance
		#define edis Eulid_distance
		#define pf int_sqr
		#define dpf double_sqr
		//// wait for addition ////
	}
	using namespace Easyuse;
	//// ---------- ---------- ---------- ---------- ---------- ---------- ////
}

using namespace GN_TAC1A3C_51TL;

const int N = 1e3 + 10, EMX = 1e5 + 10;

struct Vitaliy1 {
	int p, q;
	bool neg;
	
	Vitaliy1 operator * (Vitaliy1 ex) {
		int rp = p * ex.p, rq = q * ex.q;
		int tgcd = gcd(rp, rq);
		rp /= tgcd; rq /= tgcd;
		return Vitaliy1{rp, rq, neg != ex.neg};
	}
	
	bool operator != (Vitaliy1 ex) {
		return !(p == ex.p && q == ex.q && neg == ex.neg);
	}
	
} rec[N];

struct HACAOT {
	string oe;
	int len;
	
	HACAOT operator * (HACAOT ex) {
		int cev[EMX] = {}, a[EMX], b[EMX];
		string vita = "";
		
		for (int i = 1; i <= len; ++i) a[i] = oe[len - i] - '0';
		for (int i = 1; i <= ex.len; ++i) b[i] = ex.oe[ex.len - i] - '0';
		
		for (int i = 1; i <= ex.len; ++i)
			for (int j = 1; j <= len; ++j)
				cev[i + j - 1] += a[j] * b[i];
		
		for (int i = 1; i < len + ex.len; ++i)
			if (cev[i] > 9)
				cev[i + 1] += cev[i] / 10,
				cev[i] %= 10;
		
		int rlen = len + ex.len;
		while (cev[rlen] == 0 && rlen > 1) rlen --;
		for (int i = rlen; i >= 1; --i) vita += (char)(cev[i] + '0');
		return HACAOT{vita, rlen};
	}
	
	bool operator == (HACAOT ex) {
		return oe == ex.oe;
	}
};

struct Vitaliy2 {
	HACAOT p, q;
	bool neg;
	
	Vitaliy2 operator * (Vitaliy2 ex) {
		HACAOT rp = p * ex.p, rq = q * ex.q;
		return Vitaliy2{rp, rq, neg != ex.neg};
	}
	
	bool operator != (Vitaliy2 ex) {
		return !(p * ex.q == q * ex.p && neg == ex.neg);
	}
	
} reck[N];

struct Edge {
	int to;
	Vitaliy1 rsv;
};

struct Edgek {
	int to;
	Vitaliy2 rsv;
};

vector <Edge> g[N];
vector <Edgek> gk[N];

int T = read(), n, m;
bool vis[N], flag;

inline void IAS_DT (int u) {
	if (flag) return ;
	
	for (auto ed : g[u]) {
		int v = ed.to; auto ET = ed.rsv;
		if (vis[v]) {
			if (rec[v] != rec[u] * ET) {
				flag = 1;
				return ;
			}
		} else {
			vis[v] = 1;
			rec[v] = rec[u] * ET;
			IAS_DT (v);
		}
	}
}

inline void IAS_DC (int u) {
	if (flag) return ;
	
	for (auto ed : gk[u]) {
		int v = ed.to; auto ET = ed.rsv;
		if (vis[v]) {
			if (reck[v] != reck[u] * ET) {
				flag = 1;
				return ;
			}
		} else {
			vis[v] = 1;
			reck[v] = reck[u] * ET;
			IAS_DC (v);
		}
	}
}

HACAOT VIRA_EM (int x) {
	string res = "", t = "";
	while (x) {
		t += (char)(x % 10 + '0');
		x /= 10;
	}
	for (int i = 0; i < (int)t.size(); ++i)
		res += t[t.size() - i - 1];
	
	return HACAOT{res, (int)t.size()};
}

signed main()
{
	for (int p = 1; p <= T; ++p) {
		n = read(); m = read();
		
		if (n > 500) {
			for (int i = 1; i <= n; ++i)
				g[i].clear(), vis[i] = 0;
			
			for (int i = 1; i <= m; ++i) {
				int u = read(), v = read(), x = read(), y = read();
				bool neg = y < 0; if (neg) y = -y;
				g[u].push_back(Edge{v, Vitaliy1{x, y, neg}});
				g[v].push_back(Edge{u, Vitaliy1{y, x, neg}});
			}
			
			flag = 0;
			
			for (int i = 1; i <= n; ++i) 
				if (!vis[i]) {
					rec[i] = Vitaliy1{1, 1};
					IAS_DT (i);
				}
		} else {
			for (int i = 1; i <= n; ++i)
				gk[i].clear(), vis[i] = 0;
			
			for (int i = 1; i <= m; ++i) {
				int u = read(), v = read(), x = read(), y = read();
				bool neg = y < 0; if (neg) y = -y;
				HACAOT vrx = VIRA_EM(x), vry = VIRA_EM(y);
				gk[u].push_back(Edgek{v, Vitaliy2{vrx, vry, neg}});
				gk[v].push_back(Edgek{u, Vitaliy2{vry, vrx, neg}});
			}
			
			flag = 0;
			
			for (int i = 1; i <= n; ++i) 
				if (!vis[i]) {
					reck[i] = Vitaliy2{HACAOT{"1", 1}, HACAOT{"1", 1}, 0};
					IAS_DC (i);
				}
		}
		
		printf("Case #"); out(p, '/'); printf(": ");
		if (flag) printf("No\n");
		else printf("Yes\n");
	}
	
	return 0;
}

// You should type in the size of the tree when you use the segment tree in this code.
// T4551-G1 / DTL-10[Verring]


