#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+10;
int n,a[N],now=0,b[N],cnt[N];
vector<int> v[70],tag[70];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int x=a[i];
        while(x)x>>=1,b[i]++;
        v[b[i]].push_back(i);
        tag[b[i]].push_back(0);
        cnt[b[i]]++;
    }
    for(int i=1;i<=64;i++)
        sort(v[i].begin(),v[i].end());
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        int x=now,y=1;
        while(((x&1)||!cnt[y])&&y<65)x>>=1,y++;
        if(y==65)
        {
            cout<<"No"<<endl;
            return 0;
        }
        ans.push_back(a[v[y].back()]);
        now^=a[v[y].back()];
        v[y].pop_back();
        cnt[y]--;
    }
    cout<<"Yes"<<endl;
    for(auto i:ans)cout<<i<<" ";
    return 0;
}
/*
4 7 7 12 31 61
*/