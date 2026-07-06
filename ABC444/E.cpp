#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,d,a[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    multiset<int> s;
    int r=1,ans=0;
    s.insert(a[1]);
    for(int i=1;i<=n;i++)
    {
        while(r<=n)
        {
            r++;
            if(s.lower_bound(a[r])!=s.end()&&*s.lower_bound(a[r])-a[r]<d)break;
            if(s.upper_bound(a[r])!=s.begin()&&a[r]-*--s.upper_bound(a[r])<d)break;
            s.insert(a[r]);
            // cout<<a[r]<<endl;
        }
        r--;
        // cout<<i<<"__"<<r<<endl;
        ans+=r-i+1;
        s.erase(s.find(a[i]));
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 3
3 1 4 1 5


*/