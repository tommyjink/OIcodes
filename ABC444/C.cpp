#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N];
bool check(int x)
{
    multiset<int> s;
    for(int i=1;i<=n;i++)
        if(a[i]!=x)s.insert(a[i]);
    while(!s.empty())
    {
        if(*s.begin()+*s.rbegin()!=x)return false;
        s.erase(s.begin());
        if(s.empty())return false;
        s.erase(--s.end());
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    vector<int> v;
    if(check(a[n]))v.push_back(a[n]);
    if(check(a[1]+a[n]))v.push_back(a[1]+a[n]);
    int p=n;
    while(p>=1&&a[p]==a[n])p--;
    if(p>=1&&check(a[1]+a[p]))v.push_back(a[1]+a[p]);
    sort(v.begin(),v.end());
    // cout<<p<<endl<<a[1]+a[p]<<endl;
    for(int i=0;i<v.size();i++)
        if(i==0||v[i]!=v[i-1])cout<<v[i]<<" ";
    return 0;
}