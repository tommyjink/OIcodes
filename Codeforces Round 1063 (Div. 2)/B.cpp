#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],c[N];
string s;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        a[b[i]]=i;
        c[i]=0;
    }
    cin>>s;
    for(int i=2;i<a[n];i++)
        if(b[i]>b[1])
            c[i]=1;
    for(int i=n-1;i>a[n];i--)
        if(b[i]>b[n])
            c[i]=1;
    for(int i=2;i<a[1];i++)
        if(b[i]<b[1])
            c[i]=1;
    for(int i=n-1;i>a[1];i--)
        if(b[i]<b[n])
            c[i]=1;
    for(int i=min(a[1],a[n])+1;i<=max(a[1],a[n])-1;i++)
        c[i]=1;
    for(int i=1;i<=n;i++)
        if(s[i-1]=='1'&&!c[i])
        {
            cout<<"-1"<<endl;
            return;
        }
    cout<<"5"<<endl;
    cout<<"1 "<<a[n]<<endl;
    cout<<"1 "<<a[1]<<endl;
    cout<<a[n]<<" "<<n<<endl;
    cout<<a[1]<<" "<<n<<endl;
    cout<<min(a[1],a[n])<<" "<<max(a[1],a[n])<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
6
3
1 2 3
010
5
3 4 2 1 5
11111
6
1 3 2 4 6 5
001100
6
6 2 3 4 5 1
110110
5
2 1 4 3 5
00000
5
2 5 3 1 4
00100


*/