#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int> 
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=1e6+10;
int n,b[N],vis[N],t[N],cnt[N];
pii a[N];
vector<int> X;
void add(int x,int d)
{
    for(int i=x;i<=n;i+=lowbit(i))
        t[i]+=d;
}
int sum(int x)
{
    int res=0;
    for(int i=x;i;i-=lowbit(i))
        res+=t[i];
    return res;
}
bool dfs(int pos)
{
    if(pos>n)
    {
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
        return true;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int tmp=pos-sum(a[i].first)-1;
        if(tmp!=a[i].second&&n-a[i].first-tmp!=a[i].second)continue;
        vis[i]=true;
        add(a[i].first,1);
        b[pos]=X[a[i].first-1];
        if(dfs(pos+1))return true;
        vis[i]=false;
        add(a[i].first,-1);
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second,X.emplace_back(a[i].first);
    sort(X.begin(),X.end());
    for(int i=1;i<=n;i++)
        a[i].first=lower_bound(X.begin(),X.end(),a[i].first)-X.begin()+1;
    // for(int i=1;i<=n;i++)
    //     cout<<a[i].first<<","<<a[i].second<<endl;
    sort(a+1,a+1+n);
    if(!dfs(1))cout<<"impossible"<<endl;
    return 0;
}
/*

输入 输出
4
4 1
3 1
6 0
2 0


2 4 3 6



4
4 1
2 2
3 1
6 0


4 2 3 6

10
1 9
4 0
2 1
6 4
3 2
9 1
5 3
8 2
7 2
10 0
1 4 2 6 3 9 5 8 7 10
1 4 2 6 3 8 5 7 9 10


4
4 1
3 1
6 0
2 4
*/