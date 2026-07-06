#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int a[N],n,cnt=0,tag[N],prime[N],f[N];
void Eulor()
{
    for(int i=2;i<N;i++)
    {
        if(!tag[i])prime[++cnt]=i,f[i]=i;
        for(int j=1;j<=cnt&&i*prime[j]<N;j++)
        {
            tag[i*prime[j]]=true;
            f[i*prime[j]]=prime[j];
            if(i%prime[j]==0)break;
        }
    }
}
void solve()
{
    int p=0,tt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        // cout<<tag[a[i]]<<" ";
        if(!tag[a[i]])
        {
            if(p&&p!=a[i])
            {
                tt=1;
                continue;
            }
            p=a[i];
        }
    }
    if(tt)
    {
        cout<<"-1"<<endl;
        return;
    }
    if(!p)
    {
        cout<<"2"<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=p&&((a[i]%2==0&&a[i]/f[a[i]]<p)||(a[i]%2==1&&(a[i]-f[a[i]])<2*p)))
        {
            cout<<"-1"<<endl;
            return;
        }
    }
    cout<<p<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // s.insert(2);
    // s.insert(3);
    Eulor();
    // for(int i=1;i<=100;i++)
    //     cout<<tag[i]<<" ";
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
2 4 6 8 9 10 12 
*/