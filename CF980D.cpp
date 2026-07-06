#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;
const int N=5005,P=1e9+7,M=1e6+7;
int n,a[N],ans[N];
pii b[N];
int mp1[M+10],mp2[M+10],mp3[M+10];
vector<int> v[N];
pii gethash(vector<int> u)
{
    int base1=13331,base2=998244353;
    int res1=0,res2=0,res3=0;
    for(auto i:u)
        res1=(res1*base1%P+i+base2)%P,
        res2=(res2*base2%P+i+base1)%P;
    return pii(res1%M,res2%M);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)v[i].push_back(1e18);
        a[i]=abs(a[i]);
        for(int j=2;j*j<=a[i];j++)
        {
            int cnt=0;
            while(a[i]%j==0)a[i]/=j,cnt++;
            if(cnt&1)v[i].push_back(j);
        }
        if(a[i]>1)v[i].push_back(a[i]);
        b[i]=gethash(v[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=i;j<=n;j++)
        {
            if(!mp1[b[j].first]||!mp2[b[j].second])
                now++,mp1[b[j].first]=1,mp2[b[j].second]=1;
            ans[now]++;
        }
        for(int j=i;j<=n;j++)
            mp1[b[j].first]=mp2[b[j].second]=0;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}