#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int n,a[N];
set<int> s1,s2;
signed main()
{
    // freopen("fruit3.in","r",stdin);
    // freopen("fruit.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i])s1.insert(i);
        else s2.insert(i);
    }
    while(!(s1.empty()&&s2.empty()))
    {
        int p=0,cnt=0;
        while(p<n)
        {
            if(cnt||(!cnt&&!s1.empty()&&(s2.empty()||*s1.begin()<*s2.begin())))
            {
                auto t1=s1.lower_bound(p);
                if(t1!=s1.end())p=*t1,cout<<p<<" ",cnt++,s1.erase(t1);
                else if(cnt)break;
            }
            auto t2=s2.lower_bound(p);
            if(t2!=s2.end())p=*t2,cout<<p<<" ",cnt++,s2.erase(t2);
            else if(cnt)break;
        }
        cout<<endl;
    }
    return 0;
}
/*
1 1 0 0 1 0 0
1 0 0
0
*/