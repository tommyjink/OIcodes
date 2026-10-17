#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10,P=1e9+7;
int n,L,R,D,a[N],f[N],sum[N];
deque<int> q1,q2;
signed main()
{
    freopen("climate.in","r",stdin);freopen("climate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>L>>R>>D;for(int i=1;i<=n;i++)cin>>a[i];f[0]=sum[0]=1;int l=1;
    for(int i=1;i<=n;i++)
    {
        while(q1.size()&&a[q1.back()]<=a[i])q1.pop_back();
        q1.push_back(i);
        while(q2.size()&&a[q2.back()]>=a[i])q2.pop_back();
        q2.push_back(i);
        while(a[q1.front()]-a[q2.front()]>D)
        {
            if(q1.front()==l)q1.pop_front();
            if(q2.front()==l)q2.pop_front();
            l++;
        }
        int x=max(l-1,i-R),y=i-L;
        if(x<=y)f[i]=(sum[y]-(x?sum[x-1]:0)+P)%P;
        sum[i]=(sum[i-1]+f[i])%P;
    }
    cout<<f[n]<<endl;return 0;
}
