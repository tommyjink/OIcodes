#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,a[N],b[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+n,greater<int>());
    int p=1,free=0;
    for(int i=1;i<=n;i++)
    {
        while(p<=n&&a[p]>b[i])p++,free++;
        int j=i;
        while(j<=n&&b[j]==b[i])j++;
        j--;
        // cout<<i<<","<<j<<"."<<free<<","<<n-p+1+free<<","<<b[i]<<endl;
        if(n-p+1+free<b[i])
        {
            // cout<<"??"<<endl;
            int pp=p;
            while(pp<=n&&a[p]==a[pp])pp++;
            pp--;
            if(a[p]==b[j]&&pp-p+1>=j-i+1)
            {
                p+=j-i+1;
            }
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        else
        {
            int tmp=min(free,j-i+1);
            free-=tmp;
            if(tmp<j-i+1)
            {
                p+=j-i+1-tmp;
            }
        }
        // cout<<free<<"!"<<endl;
        i=j;
    }
    cout<<"YES"<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}