#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6,M=1e3;
int n,m,a[N],id[N],len,pos[N],f[M][M];
int st[M],ed[M],tot=0,cnt[N],siz[N],ans=0;
vector<int> c[N];
int max(int x,int y)
{
    return x>y?x:y;
}
int query(int l,int r)
{
    int res=0;
    if(id[l]==id[r])
    {
        for(int i=l;i<=r;i++)
            cnt[a[i]]++,res=max(res,cnt[a[i]]);
        for(int i=l;i<=r;i++)
            cnt[a[i]]--;
        return res;
    }
    res=f[id[l]+1][id[r]-1];
    // cout<<"!!"<<res<<endl;
    for(int i=ed[id[l]];i>=l;i--)
        while(pos[i]+res-1<siz[a[i]]&&c[a[i]][pos[i]+res-1]<=r)
            res++;
    // cout<<"!!!"<<res<<endl;
    for(int i=st[id[r]];i<=r;i++)
        while(pos[i]-res-1>=0&&c[a[i]][pos[i]-res-1]>=l)
            res++;
    // cout<<"!!!!"<<res<<endl;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    tot=len=sqrt(n);
    for(int i=1;i<=n;i++)
    {
        id[i]=(i-1)/len+1;
        if(id[i]!=id[i-1])
        {
            st[id[i]]=i;
            ed[id[i]-1]=i-1;
        }
    }
    ed[id[n]]=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]].push_back(i);
        siz[a[i]]++;
        pos[i]=c[a[i]].size();
    }
    for(int i=1;i<=tot;i++)
    {
        memset(cnt,0,sizeof(cnt));
        int tmp=0;
        for(int j=i;j<=tot;j++)
        {
            for(int k=st[j];k<=ed[j];k++)
            {
                cnt[a[k]]++;
                tmp=max(tmp,cnt[a[k]]);
            }
            f[i][j]=tmp;
        }
    }
    memset(cnt,0,sizeof(cnt));
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        l^=ans,r^=ans;
        if(l>r)
            ans=0;
        else ans=query(l,r);
        cout<<ans<<endl;
    }
    return 0;
}
/*

16 100
3 1 1 1 2 3 2 1 2 4 3 1 5 2 3 4
2 16

3 1 1 1, 2 3 2 1, 2 4 3 1, 5 2 3 4



4 1
2 3 3 3
2 4
*/