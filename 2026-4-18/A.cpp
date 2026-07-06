#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int T,n;
int a[N],cnt[10],b[10],tr[N];

struct node
{
    int id,x,y,op,c;
};

vector<node> v[85],tmp;

int getid(int a,int b,int c,int d)
{
    return ((a*3+b)*3+c)*3+d;
}

void add(int x,int v)
{
    for(int i=x;i<=n+2;i+=i&-i) tr[i]+=v;
}

int ask(int x)
{
    int s=0;
    for(int i=x;i;i-=i&-i) s+=tr[i];
    return s;
}

void cdq(vector<node> &a,int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    cdq(a,l,mid);
    cdq(a,mid+1,r);
    int i=l,j=mid+1,k=l;
    while(j<=r)
    {
        while(i<=mid&&a[i].x<=a[j].x)
        {
            if(!a[i].op) add(a[i].y+1,1);
            tmp[k++]=a[i++];
        }
        if(a[j].op) a[j].c+=ask(a[j].y+1);
        tmp[k++]=a[j++];
    }
    while(i<=mid)
    {
        if(!a[i].op) add(a[i].y+1,1);
        tmp[k++]=a[i++];
    }
    for(int p=l;p<=mid;p++)
        if(!a[p].op) add(a[p].y+1,-1);
    while(j<=r) tmp[k++]=a[j++];
    for(int p=l;p<=r;p++) a[p]=tmp[p];
}

bool chk()
{
    for(int i=1;i<=8;i++) b[i]=cnt[i];
    for(int i=1;i<=6;i++)
    {
        int x=b[i]%3;
        b[i]-=x;
        b[i+1]-=x;
        b[i+2]-=x;
        if(b[i+1]<0||b[i+2]<0) return false;
    }
    if(b[7]%3||b[8]%3) return false;
    return true;
}

int solve1()
{
    int ans=0;
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=8;i++) cnt[i]=0;
        for(int r=l;r<=n;r++)
        {
            cnt[a[r]]++;
            if((r-l+1)%3==0&&chk()) ans++;
        }
    }
    return ans;
}

int solve2()
{
    for(int i=0;i<=80;i++) v[i].clear();
    for(int i=0;i<=n+2;i++) tr[i]=0;
    int c1=0,c2=0,c3=0,c4=0;
    v[0].push_back({0,0,0,0,0});
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) c1++;
        if(a[i]==2) c2++;
        if(a[i]==3) c3++;
        if(a[i]==4) c4++;
        int r1=c1%3,r2=c2%3,r3=c3%3,r4=c4%3;
        for(int x=0;x<=2;x++)
            for(int y=0;y<=2;y++)
            {
                int k=x+y;
                if(c2<k||c3<k) continue;
                int t1=(r1-x+3)%3;
                int t2=(c2-k)%3;
                int t3=(c3-k)%3;
                int t4=(r4-y+3)%3;
                v[getid(t1,t2,t3,t4)].push_back({i,c2-k,c3-k,1,0});
            }
        v[getid(r1,r2,r3,r4)].push_back({i,c2,c3,0,0});
    }
    int ans=0;
    for(int i=0;i<=80;i++)
    {
        if(!v[i].size()) continue;
        tmp.resize(v[i].size());
        cdq(v[i],0,v[i].size()-1);
        for(auto j:v[i])
            if(j.op) ans+=j.c;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>T;
    while(T--)
    {
        cin>>n;
        int mx=0;
        for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
        if(n<=3000) cout<<solve1()<<endl;
        else if(mx<=4) cout<<solve2()<<endl;
        else cout<<solve1()<<endl;
    }

    return 0;
}
