#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,cnt=0,lst=0;
string s;
vector<int> e;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>s;
    int p=0;
    while(p<n)
    {
        int t=p;
        while(p<n&&s[p]=='1')
            p++;
        if(p>t)cnt++;
        t=p;
        while(p<n&&s[p]=='0')
            p++;
        if(p>t&&t!=0&&p!=n)e.push_back(p-t);
    }
    sort(e.begin(),e.end());
    for(auto i:e)
        if(k>=i)
            cnt--,k-=i;
    cout<<cnt<<endl;
    return 0;
}