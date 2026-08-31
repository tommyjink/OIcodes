#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=3e5+10;
int n,m,x[N],dir[N],tim[N];
int cnta=0,cntb=0;
struct node
{
    int x,dir,id;
}a[N],b[N];
bool cmp(node x,node y){return x.x<y.x;}
void work(node *a,int cnta)
{
    stack<node> s;
    for(int i=1;i<=cnta;i++)
    {
        if(a[i].dir==0)s.push(a[i]);
        else if(!s.empty()&&s.top().dir==0)
        {
            node j=s.top();s.pop();
            tim[j.id]=tim[a[i].id]=(a[i].x-j.x)/2;
        }
        else s.push(a[i]);
    }
    deque<node> q;
    while(!s.empty())q.push_front(s.top()),s.pop();
    while(!q.empty()&&q.front().dir==1)
    {
        node t1=q.front();q.pop_front();
        if(q.empty()){q.push_front(t1);break;}
        node t2=q.front();
        if(t2.dir==1)
        {
            q.pop_front();
            tim[t1.id]=tim[t2.id]=(t1.x+t2.x)/2;
        }
        else {q.push_front(t1);break;}
    }
    while(!q.empty()&&q.back().dir==0)
    {
        node t1=q.back();q.pop_back();
        if(q.empty()){q.push_back(t1);break;}
        node t2=q.back();
        if(t2.dir==0)
        {
            q.pop_back();
            tim[t1.id]=tim[t2.id]=(2*m-t1.x-t2.x)/2;
        }
        else {q.push_back(t1);break;}
    }
    if(q.size()==2)tim[q.front().id]=tim[q.back().id]=(2*m-(q.back().x-q.front().x))/2;
}
void solve()
{
    cnta=cntb=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>x[i],tim[i]=-1;
    for(int i=1;i<=n;i++)
    {
        char c;cin>>c;
        if(c=='R')dir[i]=0;
        else dir[i]=1;
    }
    for(int i=1;i<=n;i++)
        if(x[i]&1)a[++cnta]={x[i],dir[i],i};
        else b[++cntb]={x[i],dir[i],i};
    sort(a+1,a+1+cnta,cmp);
    sort(b+1,b+1+cntb,cmp);
    work(a,cnta);
    work(b,cntb);
    for(int i=1;i<=n;i++)
        cout<<tim[i]<<' ';
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}