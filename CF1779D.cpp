#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],b[N],c[N],d[N*4],cnt=0,lst[N],nxt[N],num[N];
vector<int> pos[N*4];
void solve()
{
    cin>>n;
    cnt=0;
    for(int i=1;i<=n;i++)cin>>a[i],d[++cnt]=a[i];
    for(int i=1;i<=n;i++)cin>>b[i],d[++cnt]=b[i];
    cin>>m;
    for(int i=1;i<=m;i++)cin>>c[i],d[++cnt]=c[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]<b[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    sort(c+1,c+1+m);
    sort(d+1,d+1+cnt);
    cnt=unique(d+1,d+1+cnt)-d-1;
    for(int i=1;i<=cnt;i++)num[i]=0,pos[i].clear();
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(d+1,d+1+cnt,a[i])-d;
        b[i]=lower_bound(d+1,d+1+cnt,b[i])-d;
    }
    for(int i=1;i<=m;i++)
    {
        c[i]=lower_bound(d+1,d+1+cnt,c[i])-d;
        num[c[i]]++;
        // cout<<c[i]<<" ";
    }

    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        while(!st.empty()&&b[st.top()]<=b[i])st.pop();
        if(!st.empty())lst[i]=st.top();
        else lst[i]=0;
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&b[st.top()]<=b[i])st.pop();
        if(!st.empty())nxt[i]=st.top();
        else nxt[i]=n+1;
        st.push(i);
    }
    for(int i=1;i<=n;i++)
        pos[b[i]].push_back(i);
    for(int i=1;i<=cnt;i++)
    {
        int need=pos[i].size(),p=-1;
        for(int j=0;j<pos[i].size();j++)
        {
            if(p>=0&&j>0&&lst[pos[i][j]]<pos[i][p])need--;
            else if(a[pos[i][j]]==b[pos[i][j]])need--;
            if(a[pos[i][j]]!=b[pos[i][j]])p=j;
        }
        if(need>num[i])
        {
            // cout<<i<<"!"<<d[i]<<endl;
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
7
3
3 3 3
2 1 2
2
1 2
YES

6
3 4 4 6 3 4
3 1 2 3 2 3
3
3 2 3
NO

10
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
10
1 2 3 4 5 6 7 8 9 10
YES

3
1 1 1
1 1 2
12
4 2 4 3 1 5 6 3 5 6 2 1
NO

13
7 9 4 5 3 3 3 6 8 10 3 2 5
5 3 1 5 3 2 2 5 8 5 1 1 5
8
1 5 3 5 4 2 3 1
YES

13
7 9 4 5 3 3 3 6 8 10 3 2 5
5 3 1 5 3 2 2 5 8 5 1 1 5
7
1 5 3 4 2 3 1
NO

3
19747843 2736467 938578397
2039844 2039844 2039844
1
2039844
YES


*/