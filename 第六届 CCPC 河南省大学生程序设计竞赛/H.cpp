#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6,P=998244353;
int n,ans=1,cnt=0,maxval=0;
vector<int> a;
priority_queue<int,vector<int>,greater<int> > q;
map<int, int> mp;
int qpow(int x,int y,int p)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%p;
        y>>=1;
        x=x*x%p;
    }
    return res;
}
int ni(int x)
{
    return qpow(x,P-2,P);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            int t=q.top();
            // cout<<"!"<<t<<endl;
            if(t<maxval)
            {
                cout<<"0"<<endl;
                return 0;
            }
            maxval=max(maxval,t);
            q.pop();
            ans=ans*ni(cnt)%P;
            ans=ans*mp[t]%P;
            cnt--;
            mp[t]--;
        }
        else
        {
            q.push(x);
            if(!mp.count(x))mp[x]=1;
            else mp[x]++;
            cnt++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

/*

4
1 -1 2 -1 3 -1 4 -1

1

3
1 2 -1 -1 1 -1



2
1 2 -1 -1


499122177
*/