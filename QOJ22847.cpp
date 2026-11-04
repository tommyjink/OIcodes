#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,x;
int cnt2=0,cnt3=0;
deque<int> A;
void solve()
{
    A.clear();
    cin>>n>>x;
    if(n==1&&x!=2){cout<<"No"<<endl;return;}
    if(x==0)
    {
        cout<<"Yes"<<endl;
        for(int i=n;i>=1;i--)cout<<i<<" "<<i<<" ";
        cout<<endl;
        return;
    }
    int now=0;
    for(int i=2;i*i<=x&&i-1<=n&&now<=n;i++)
    {
        while(x%i==0)
        {
            x/=i;
            now++;
            A.push_back(now);
            A.push_back(now);
            for(int j=2;j<=i-1;j++)
            {
                now++;
                A.pop_back();
                A.push_back(now);
                A.push_back(now-1);
                A.push_back(now);
            }
        }   
    }
    if(x>1&&x-1<=n)
    {
        now++;
        A.push_back(now);
        A.push_back(now);
        for(int j=2;j<=x-1;j++)
        {
            now++;
            A.pop_back();
            A.push_back(now);
            A.push_back(now-1);
            A.push_back(now);
        }
        x=1;
    }
    if(x>1||now>n){cout<<"No"<<endl;return;}
    for(int i=now+1;i<=n;i+=2)
    {
        if(i==n)
        {
            A.push_front(i);
            A.push_back(i);
        }
        else
        {
            A.push_back(i+1);
            A.push_back(i);
            A.push_back(i+1);
            A.push_back(i);
        }
    }
    cout<<"Yes"<<endl;
    for(int i:A)cout<<i<<" ";
    cout<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}