#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m,q,mov[N][4],col[N],lv[N],exi[N],ans=0;
bool tag1[N],tag2[N],tag3[N];
vector<int> v;
struct node
{
    int x,y,z;
};
inline int c(int x,int y)
{
    return (x-1)*m+y;
}
void input()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<m;j++)
        {
            int now=s[j-1]-'0';
            mov[c(i,j)][0]=now;
            mov[c(i,j+1)][1]=now;
        }
    }
    for(int i=1;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            int now=s[j-1]-'0';
            mov[c(i,j)][2]=now;
            mov[c(i+1,j)][3]=now;
        }
    }
}
inline void tag(int x,int y,int num)
{
    if(!tag1[c(x,y)]&&!tag2[c(x,y)]&&!tag3[c(x,y)])
        ans++,v.emplace_back(c(x,y));
    if(num==1)tag1[c(x,y)]=true;
    if(num==2)tag2[c(x,y)]=true;
    if(num==3)tag3[c(x,y)]=true;
}
void bfs3(int sx,int sy,int cc,int ll)
{
    queue<pii> q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii t=q.front();
        q.pop();
        int x=t.first,y=t.second;
        if(tag3[c(x,y)])continue;
        tag(x,y,3);
        tag3[c(x,y)]=true;
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<1||yy<1||xx>n||yy>m||mov[c(x,y)][i]!=3||tag3[c(xx,yy)])
                continue;
            if(exi[c(xx,yy)])
            {
                if(col[c(xx,yy)]!=cc&&lv[c(xx,yy)]<=ll)
                    tag(xx,yy,3);
            }
            else q.push(pii(xx,yy));
        }
    }
}   
void bfs2(int sx,int sy,int cc,int ll)
{
    queue<node> q;
    q.push((node){sx,sy,0});
    q.push((node){sx,sy,1});
    q.push((node){sx,sy,2});
    q.push((node){sx,sy,3});
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        int x=t.x,y=t.y,i=t.z;
        tag(x,y,2);
        int xx=t.x+dx[i];
        int yy=t.y+dy[i];
        if(xx<1||yy<1||xx>n||yy>m)continue;
        if(tag2[c(xx,yy)]||mov[c(x,y)][i]!=2)continue;
        if(exi[c(xx,yy)])
        {
            if(col[c(xx,yy)]!=cc&&lv[c(xx,yy)]<=ll)
                tag(xx,yy,2);
        }
        else q.push((node){xx,yy,i});
    }
}
void bfs1(int sx,int sy,int cc,int ll)
{
    for(int i=0;i<4;i++)
    {
        int xx=sx+dx[i];
        int yy=sy+dy[i];
        if(xx<1||yy<1||xx>n||yy>m)continue;
        if(tag1[c(xx,yy)]||mov[c(sx,sy)][i]!=1)continue;
        // cout<<xx<<","<<yy<<endl;
        if(exi[c(xx,yy)])
        {
            if(col[c(xx,yy)]!=cc&&lv[c(xx,yy)]<=ll)
            {
                tag(xx,yy,1);
            }
        }
        else tag(xx,yy,1);
    }
}
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<(tag1[c(i,j)]|tag2[c(i,j)]|tag3[c(i,j)])<<" ";
        }
        cout<<endl;
    }
}
void solve()
{
    memset(mov,0,sizeof(mov));
    memset(col,0,sizeof(col));
    memset(lv,0,sizeof(lv));
    memset(exi,0,sizeof(exi));
    input();
    while(q--)
    {
        ans=0;
        int cc,ll,x,y;
        cin>>cc>>ll>>x>>y;
        bfs1(x,y,cc,ll);
        bfs2(x,y,cc,ll);
        bfs3(x,y,cc,ll);
        exi[c(x,y)]=true;
        col[c(x,y)]=cc;
        lv[c(x,y)]=ll;
        // print();
        cout<<ans-1<<endl;
        for(auto i:v)tag1[i]=tag2[i]=tag3[i]=0;
        v.clear();
    }
}
signed main()
{
    // freopen("./chess/chess3.in","r",stdin);
    // freopen("test.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*

1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2




*/