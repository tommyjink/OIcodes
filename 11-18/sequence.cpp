#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=1e6+10;
int n,a[N],b[N],res1=0,res2=0;
void solve1()
{
    int cnt[2]={0,0};
    vector<int> v[2];
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
        {
            cnt[1]++;
            v[1].emplace_back(i);
        }
        else
        {
            cnt[0]++;
            v[0].emplace_back(i);
        }
    }
    for()
}
void solve2()
{

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    return 0;
}