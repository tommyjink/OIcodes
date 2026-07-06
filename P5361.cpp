#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e4+10,M=1e5+10;
int T,n,m,Deg[N],deg[N];
pii E[M];
vector<int> G[N];
struct Node{int u,dis;};
bool operator <(Node A,Node B){return A.dis>B.dis;}
int vis[N],res;
int ot[N],ot_top,ans[N],ans_top;

void solve(int mn=-1){
	priority_queue<Node> q;
	for(int i=1;i<=n;i++)vis[i]=0,deg[i]=Deg[i];
	for(int i=1;i<=n;i++)q.push({i,deg[i]});
	int flg=0;
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		if(mn==-1)res=max(res,deg[u]);
		else{
			if(deg[u]>=mn)flg=1;
			if(flg)ot[++ot_top]=u;
		}
		for(auto v:G[u])if(vis[v]==0)deg[v]--,q.push({v,deg[v]});
	}
}

void Solve(){
	for(int i=1;i<=n;i++)vis[i]=0,deg[i]=Deg[i];
	priority_queue<Node> q;
	for(int i=1;i<=n;i++)q.push({i,deg[i]});
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		ans[++ans_top]=u;
		for(auto v:G[u])if(vis[v]==0){
			vis[v]=1;
			for(auto t:G[v])if(vis[t]==0)deg[t]--,q.push({t,deg[t]});
		}
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n>>m,ot_top=0,ans_top=0;
		for(int i=1;i<=n;i++)deg[i]=0,G[i].clear();
		for(int i=1;i<=m;i++){int u,v;cin>>u>>v;E[i]={min(u,v),max(u,v)};}
		sort(E+1,E+m+1),m=unique(E+1,E+m+1)-E-1;
		for(int i=1;i<=m;i++){
			deg[E[i].first]++,deg[E[i].second]++;
			G[E[i].first].push_back(E[i].second),G[E[i].second].push_back(E[i].first);
		}
		for(int i=1;i<=n;i++)Deg[i]=deg[i];
		res=deg[1];for(int i=2;i<=n;i++)res=min(res,deg[i]);
		solve(),solve(res);
		cout<<ot_top<<' ';for(int i=1;i<=ot_top;i++)cout<<ot[i]<<' ';cout<<endl;
		Solve();
		cout<<ans_top<<' ';for(int i=1;i<=ans_top;i++)cout<<ans[i]<<' ';cout<<endl;
	}
	return 0;
}
