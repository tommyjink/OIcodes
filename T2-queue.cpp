#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6;
int n, len[N],pre[N],tag[N],f[N],ans=0,st[2][N];
int tot[2]={0};
string s[N], z[N],tt[2][N];
signed main()
{
    // freopen("queue.in","r",stdin);
    // freopen("queue.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout<<("abc">"abcd");
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    sort(s+1,s+1+n);
    for(int i=1;i<=n;i++)
    {
        z[i]=s[i];
        int len=s[i].length();
        for(int j=0;j<len;j++)
            if(s[i][j]=='m')
                tag[i]=true;
        for(int j=1;j<=(int)len/2;j++)
            swap(z[i][j-1],z[i][len-j]);
        // cout<<z[i]<<" "<<len<<endl;
        while(tot[tag[i]]&&z[i]<=z[(st[tag[i]][tot[tag[i]]])])tot[tag[i]]--;
        st[tag[i]][++tot[tag[i]]]=i,tt[tag[i]][tot[tag[i]]]=z[i];
        // cout<<"!!"<<endl;
        int an=tag[i]^1;
        for(int i=1;i<=tot[tag[i]];i++)
            cout<<st[tag[i]][i]<<" ";
        cout<<endl;
        if(tot[an])pre[i]=st[an][lower_bound(tt[an]+1,tt[an]+1+tot[an],z[i])-tt[an]];
        while(pre[i]&&tag[i]==tag[pre[i]])
            pre[i]=pre[pre[i]];
        f[i]=max(f[pre[pre[pre[i]]]]+1,f[pre[i]]+1);
        ans=max(ans,f[i]);
        printf("pre[%lld]=%lld\n",i,pre[i]);
    }
    cout<<ans<<endl;
    return 0;
}