#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int T,n,k,a[N],b[N],p[N],tot,mn[N],mx[N],l[N],r[N],id[N],cnt,fr[N],fcnt;
bool cmp(int x,int y)
{
    return l[x]<l[y];
}
bool chk(int lim,int op)
{
    tot=cnt=fcnt=0;
    for(int i=1;i<=n;i++)
    {
        if(op)b[i]=a[i];
        if(!a[i])p[++tot]=i;
    }
    for(int i=1;i<=k;i++)
    {
        if(!mx[i])fr[++fcnt]=i;
        else
        {
            if(mx[i]-mn[i]>lim)return false;
            l[i]=max(1ll,mx[i]-lim);
            r[i]=min(mn[i],n-lim);
            if(l[i]>r[i])return false;
            id[++cnt]=i;
        }
    }
    sort(id+1,id+1+cnt,cmp);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    int now=1,pos=1,j=1;
    while(j<=tot)
    {
        int x=p[j];
        while(now<=cnt&&l[id[now]]<=x)
        {
            q.push({r[id[now]],id[now]});
            now++;
        }
        while(!q.empty()&&q.top().first<x-lim)q.pop();
        if(!q.empty())
        {
            int rr=min(q.top().first,x)+lim,c=q.top().second;
            q.pop();
            while(j<=tot&&p[j]<=rr)
            {
                if(op)b[p[j]]=c;
                j++;
            }
        }
        else if(pos<=fcnt)
        {
            int rr=x+lim,c=fr[pos++];
            while(j<=tot&&p[j]<=rr)
            {
                if(op)b[p[j]]=c;
                j++;
            }
        }
        else return false;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=k;i++)mn[i]=n+1,mx[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i])
            {
                mn[a[i]]=min(mn[a[i]],i);
                mx[a[i]]=i;
            }
        }
        int L=0,R=n-1;
        while(L<R)
        {
            int mid=(L+R)>>1;
            if(chk(mid,0))R=mid;
            else L=mid+1;
        }
        chk(L,1);
        for(int i=1;i<=n;i++)cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}
