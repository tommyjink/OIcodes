#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3;
int n,a[N*N];
map<int,int> tag;
vector<int> ans;
int gcd(int x,int y)
{
    if(x<y)swap(x,y);
    return y==0?x:gcd(y,x%y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n*n;i++)
        cin>>a[i];
    sort(a+1,a+1+n*n);
    for(int i=n*n;i>=1;i--)
    {
        if(tag[a[i]])
        {
            tag[a[i]]--;
            continue;
        }
        for(auto j:ans)
            tag[gcd(a[i],j)]+=2;
        ans.push_back(a[i]);
        if(ans.size()>=n)break;
    }
    for(int i:ans)
        cout<<i<<" ";
    return 0;
}