#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,h,t1=0,t2=0,ans=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>h;
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    for(int i=1;i<=n;i++,t1-=h,t2+=h)
    {
        // if(i>1)cout<<q1.top()+t1<<","<<q2.top()+t2<<endl;
        int x;cin>>x;
        if(i==1)
        {
            q1.push(x-t1);
            q2.push(x-t2);
            // cout<<x-t2<<"?"<<endl;
            continue;
        }
        int l=t1+q1.top();
        int r=t2+q2.top();
        if(x>=l&&x<=r)
        {
            q1.push(x-t1);
            q2.push(x-t2);
            // cout<<x-t2<<"?"<<endl;
        }
        else if(x<l)
        {
            ans+=l-x;
            q2.push(l-t2);
            // cout<<l-t2<<"?"<<endl;
            q1.push(x-t1);
            q1.push(x-t1);
            q1.pop();
        }
        else
        {
            ans+=x-r;
            q1.push(r-t1);
            // cout<<"q2.pop()"<<q2.top()+t2<<endl;
            q2.push(x-t2);
            q2.push(x-t2);
            q2.pop();
            // cout<<q2.top()+t2<<"!!"<<endl;
            // if(q2.empty())cout<<"ASDSADSDS"<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}