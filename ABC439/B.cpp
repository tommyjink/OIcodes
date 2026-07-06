#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
vector<int> div(int x)
{
    vector<int> res;
    while(x)
    {
        res.emplace_back(x%10);
        x/=10;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int c=1e7;
    while(c--)
    {
        vector<int> v=div(n);
        int now=0;
        for(auto i:v)now+=i*i;
        if(now==1)
        {
            cout<<"Yes"<<endl;
            exit(0);
        }
        n=now;
    }
    cout<<"No"<<endl;
    return 0;
}