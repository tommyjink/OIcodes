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
    cin>>n>>x;
    if(n==1&&x!=2){cout<<"No"<<endl;return;}
    if(x==0)
    {
        cout<<"Yes"<<endl;
        for(int i=n;i>=1;i--)cout<<i<<" "<<i<<" ";
        cout<<endl;
        return;
    }
    cnt2=cnt3=0;
    while(x%2==0)cnt2++,x/=2;
    while(x%3==0)cnt3++,x/=3;
    // cout<<cnt2<<" "<<cnt3<<endl;
    if(x>1||cnt2+cnt3*2>n){cout<<"No"<<endl;return;}
    A.clear();
    for(int i=1;i<=cnt2;i++)
        A.push_back(i),A.push_back(i);
    for(int i=cnt2+1;i<=cnt2+cnt3*2;i+=2)
    {
        A.push_back(i);
        A.push_back(i+1);
        A.push_back(i);
        A.push_back(i+1);
    }
    for(int i=cnt2+cnt3*2+1;i<=n;i+=2)
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