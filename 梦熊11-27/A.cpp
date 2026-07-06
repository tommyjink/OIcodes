#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int n,m,k;
vector<int> ans[N];
struct node
{
	int ed,num;
};
struct docu
{
	int s,t,num;
}doc[N];
bool operator <(docu x,docu y)
{
	return x.t<y.t;
}
bool operator <(node x,node y)
{
	return x.ed==y.ed?x.num>y.num:x.ed>y.ed;
}
bool cmp(docu x,docu y)
{
	return x.t<y.t;
}
priority_queue<node> q;
priority_queue<int,vector<int>,greater<int> > q0;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>doc[i].s>>doc[i].t;
		doc[i].num=i;
	}
	sort(doc+1,doc+1+n,cmp);
	// cout<<"所有文档排序结果："<<endl;
	// for(int i=1;i<=n;i++)
		// cout<<doc[i].num<<" ";
	// cout<<endl;
	for(int i=1;i<=m;i++)
		q0.push(i);
	for(k=1;k<=n;k++)
	{
		// cout<<"i="<<k<<":"<<endl;
		// cout
		while(!q.empty()&&q.top().ed<doc[k].t)
		{
			// cout<<"空闲打印机多一个："<<q.top().num<<endl;
			q0.push(q.top().num);
			q.pop();
		}
		if(!q0.empty())
		{
			int t=q0.top();q0.pop();
			// cout<<"使用一个空闲的打印机"<<t<<"   ";
			// cout<<"这个打印机结束时间为"<<doc[k].t+doc[k].s-1<<endl;
			q.push((node){doc[k].t+doc[k].s-1,t});
			ans[t].push_back(doc[k].num);
		}
		else
		{
			// cout<<"没有空闲的打印机，使用打印机:"<<q.top().num<<"   ";
			// cout<<"这个打印机结束时间变为："<<q.top().ed+doc[k].s<<endl;
			ans[q.top().num].push_back(doc[k].num);
			q.push((node){q.top().ed+doc[k].s,q.top().num});
			q.pop();
		}
	}
	// cout<<"输出答案："<<endl;
	for(int i=1;i<=m;i++)
	{
		int len=ans[i].size();
		sort(ans[i].begin(),ans[i].end());
		cout<<len<<" ";
		for(int j=0;j<len;j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}