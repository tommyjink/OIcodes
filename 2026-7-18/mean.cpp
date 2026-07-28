#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int T,n,k,tot,mid,num;
int cnt[N],a[N],ans[N],id[N],odd[N],sta[N];
struct node
{
    int x,y,z;
}p[N];
bool dfs(int need)
{
    if(!need)return true;
    int free=0,z=0;
    for(int i=1;i<mid;i++)
    {
        if(!sta[i])
        {
            free++;
            z=i;
        }
    }
    if(free<need*3)return false;
    for(int x=1;x<z;x++)
    {
        int y=z-x;
        if(x>=y)break;
        if(sta[x]||sta[y])continue;
        sta[x]=sta[y]=sta[z]=1;
        p[++num]={x,y,z};
        if(dfs(need-1))return true;
        num--;
        sta[x]=sta[y]=sta[z]=0;
    }
    if(free>need*3)
    {
        sta[z]=2;
        if(dfs(need))return true;
        sta[z]=0;
    }
    return false;
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cnt[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        ans[i]=0;
    }
    tot=0;
    int one=0,rt=0;
    for(int i=1;i<=k;i++)
    {
        if(cnt[i]&1)
        {
            odd[++tot]=i;
            if(cnt[i]==1)one++,rt=i;
        }
    }
    if((n%2==0&&tot)||(n%2==1&&one>1))
    {
        cout<<"NO"<<endl;
        return;
    }
    mid=(n+1)/2;
    for(int i=1;i<mid;i++)
        sta[i]=0;
    if(n&1)
    {
        if(!rt)rt=odd[1];
        ans[mid]=rt;
        cnt[rt]--;
    }
    int m=0;
    for(int i=1;i<=tot;i++)
        if(odd[i]!=rt)id[++m]=odd[i];
    num=0;
    if(m/2>25||!dfs(m/2))
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=m;i+=2)
    {
        int x=id[i],y=id[i+1],now=(i+1)/2;
        ans[mid-p[now].x]=x;
        ans[mid-p[now].y]=x;
        ans[mid+p[now].z]=x;
        ans[mid+p[now].x]=y;
        ans[mid+p[now].y]=y;
        ans[mid-p[now].z]=y;
        cnt[x]-=3;
        cnt[y]-=3;
    }
    int l=1,r=n;
    for(int i=1;i<=k;i++)
    {
        while(cnt[i])
        {
            while(ans[l])l++;
            while(ans[r])r--;
            ans[l]=ans[r]=i;
            l++,r--;
            cnt[i]-=2;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" \n"[i==n];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)solve();
    return 0;
}
