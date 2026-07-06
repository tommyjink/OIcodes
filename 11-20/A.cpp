#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e7+10;
int p,q,a[N],b[N],n,m,cnt[N];
int num[N],ans=0;
void input()
{
    int A,B,C,D,E,F;
    cin>>p>>q;
    cin>>n>>a[1]>>a[2]>>A>>B>>C;
    cin>>m>>b[1]>>b[2]>>D>>E>>F;
    a[1]%=p,a[2]%=p;
    b[1]%=p-1,b[2]%=p-1;
    for(int i=3;i<=n;i++)a[i]=((A*a[i-1]%p-B*a[i-2]%p-C)%p+p)%p;
    for(int i=3;i<=m;i++)b[i]=((D*b[i-1]%(p-1)+E*b[i-2]%(p-1)+F)%(p-1)+p-1)%(p-1);
    for(int i=1;i<=n;i++)cnt[a[i]]++;
    for(int i=1;i<=m;i++)num[b[i]]++;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    // for(int i=1;i<=m;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=m;i++)
    //     cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=0;i<p;i++)
        for(int tot=0,now=1;tot<=p-1;tot++,now=now*i%p)
            if(now<=q)ans+=cnt[i]*num[tot];
    cout<<ans<<endl;
    return 0;
}
/*


输入 
5 3
3 2 2 1 0 4
3 3 2 4 2 1

输出
6



5 3
10 2 2 1 5 4
10 3 1 5 2 1


5 3
2 100 1 1 1 1 
2 4 1 1 1 1 


5 3
2 100 1 1 1 1 
2 4 1 1 1 1 
*/