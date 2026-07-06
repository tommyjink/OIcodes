#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6+10;
int n,k,w[N*4];
vector<int> v[N];
struct node{int x,l,r,op;};
struct node1{int l,r,val;}t[N*4];
bool cmp(node x,node y){return x.x<y.x;}
vector<node> q;

void pushup(int k)
{
    if(t[k].val) w[k]=t[k].r-t[k].l+1;
    else if(t[k].l==t[k].r) w[k]=0; 
    else w[k]=w[k*2]+w[k*2+1];
}

void build(int k,int l,int r)
{
    t[k].l=l,t[k].r=r; t[k].val=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
}

void add(int k,int l,int r,int d)
{
    if(t[k].l>r||t[k].r<l)return;
    if(l<=t[k].l&&t[k].r<=r)
    {
        t[k].val+=d;
        pushup(k);
        return;
    }
    add(k*2,l,r,d);
    add(k*2+1,l,r,d);
    pushup(k);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    
    
    for(int i=1;i<=1000000;i++)
    {
        if(v[i].empty()) continue;
        int m=v[i].size();
        for(int j=0;j<m;j++)
        {
            if(j+k-1>=m)continue;
            int l=1,r=n;
            if(j>0)l=v[i][j-1]+1;
            if(j+k<m)r=v[i][j+k]-1;
            
            int x=l,xx=v[i][j],y=v[i][j+k-1],yy=r;
            
            if(x<=xx && y<=yy){
                q.emplace_back((node){x,y,yy,1});
                q.emplace_back((node){xx+1,y,yy,-1});
            }
        }
    }
    
    sort(q.begin(),q.end(),cmp);
    int sum=0;
    
    
    if(!q.empty()){
        for(int i=0;i<(int)q.size()-1;i++)
        {
            add(1,q[i].l,q[i].r,q[i].op);
            sum+=w[1]*(q[i+1].x-q[i].x);
        }
    }
    
    cout<<n*(n-1)/2+n-sum<<endl;
    return 0;
}