#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;

const int N=2e5+10,mod=1e9+7,P=998244353;

int t,n,m;
int ad[N],de[N],ant[N],dnt[N],w1[N],w2[N],s1,s2;

struct node
{
    int x,y;
}b[N];

bool cmp(node x,node y)
{
    if(x.x!=y.x)return x.x<y.x;
    return x.y<y.y;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            ad[i]=0;
            de[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            w1[i]=i*i%mod*i%mod;
            w2[i]=(i+114514)*(i+114514)%P*(i+114514)%P;
            ant[i]=ad[a];
            ad[a]=i;
            dnt[i]=de[b];
            de[b]=i;
            // for(int j=1;j<=m;j++)
            //     cout<<dnt[j]<<",";
            // cout<<endl;
        }
        s1=s2=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=de[i];j;j=dnt[j])
            {
                s1=(s1-w1[j]+mod)%mod;
                s2=(s2-w2[j]+P)%P;
            }
            for(int j=ad[i];j;j=ant[j])
            {
                s1=(s1+w1[j])%mod;
                s2=(s2+w2[j])%P;
            }
            b[i]={s1,s2};
        }
        sort(b+1,b+n+1,cmp);
        // for(int i=1;i<=n;i++)
        //     cout<<b[i].x<<","<<b[i].y<<endl;
        int mx=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(i==1||b[i].x!=b[i-1].x||b[i].y!=b[i-1].y)sum=1;
            else sum++;
            mx=max(mx,sum);
        }
        cout<<n-mx<<endl;
    }
    return 0;
}

/*

7
8 3
1 8
2 7
4 5
13 4
1 13
2 12
3 11
4 10
10 2
2 3
3 4
10 4
3 8
5 10
2 10
4 10
4 1
1 3
5 2
3 5
1 4
5 2
2 5
1 3


*/