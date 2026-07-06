#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,s,a,b,ans=0,k=0;
vector<int> c;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s>>a>>b;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x<=a+b)
            c.push_back(y),k++;
    }
    sort(c.begin(),c.end());
    for(int i=0;i<=(int)c.size()-1;i++)
        if(s-c[i]>=0)
            ans++,s-=c[i];
    cout<<ans<<endl;
    return 0;
}