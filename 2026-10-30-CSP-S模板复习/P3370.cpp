#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=998244353,b=13331;
int base[N],a[N];
void init()
{
    base[0]=1;
    for(int i=1;i<N;i++)
        base[i]=base[i-1]*b%P;
}
int cal(string s)
{
    int n=s.length(),res=0;
    for(int i=0;i<n;i++)
        res=(res+base[i]*s[i]%P)%P;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    init();
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        a[i]=cal(s);
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(i==1||a[i]!=a[i-1])ans++;
    cout<<ans<<endl;
    return 0;
}