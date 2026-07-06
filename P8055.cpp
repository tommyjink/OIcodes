#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+100,M=30,P=1e9+7;
int n,q,sum1[N],sum2[N],a[N];
vector<int> b;
string s;
int qpow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)res=res*x%P;
        y>>=1;
        x=x*x%P;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q>>s;
    for(int i=1;i<=n;i++)
    {
        sum1[i]=sum1[i-1]+s[i-1]-'0';//highbit
        sum2[i]=sum2[i-1]+((s[i-1]-'0')^1);//lowbit
        if(sum2[i]-sum1[i]==1)b.push_back(i);
        cout<<sum2[i]<<" ";
    }
    cout<<endl;
    while(q--)
    {
        int l,r,x,cnt=0,tag=0;
        vector<int> v;
        cin>>l>>r>>x;
        for(int i=0;i<=M;i++)
        {
            if(x&(1ll<<i)) cnt++,v.push_back(i),tag=true,cout<<"1";
            else if(tag) a[i]++,cout<<"0";
            a[i+1]=a[i];
        }
        cout<<endl;
        for(int i=0;i<=M;i++)
            cout<<a[i]<<" ";
        cout<<endl;
        if(cnt==0){cout<<"0"<<endl;continue;}
        if(cnt==1){cout<<qpow(2,r-l+1+v[0])<<endl;continue;}
        int p=lower_bound(sum2+l,sum2+r+1,sum2[l-1]+a[v[cnt-1]])-sum2;
        cout<<p<<"!"<<sum2[l-1]+a[v[cnt-1]]<<"!"<<v[cnt-1]<<"!"<<a[v[cnt-1]]<<endl;
        if(p<l||p>r)
        {
            p=lower_bound(a,a+M,sum2[r]-sum2[l-1])-a;
            int res=(x^((1ll<<v[cnt-1])|(x^((x>>p)<<p)))%P+qpow(2,v[cnt-1]+sum1[r]-sum1[l-1])+qpow(2,p))%P;
            cout<<res<<endl;
            continue;
        }
        int k=lower_bound(b.begin(),b.end(),p)-b.begin();
        if(k>b.size()-1)
        {
            cout<<(qpow(2,sum1[r]-sum1[l-1]+v[cnt-1])+qpow(2,sum2[r]-sum2[p-1]+v[cnt-1]-1))%P<<endl;
            continue;
        }
        k=b[k];
        int ans=qpow(2,r-k+sum1[k]-sum1[p-1]+v[cnt-1]+1);
        cout<<ans<<endl;

    }
    return 0;
}

/*
8 8
01100001
1 2 3
1 4 9
2 6 9
3 8 9
6 8 2
8 8 3
5 8 6
2 8 17

8
36
40
64
16
5
64
144

*/