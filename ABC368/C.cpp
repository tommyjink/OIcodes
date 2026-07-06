#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,a[N],t=0;
void cal(int x,int y)
{
    int k=x/5,p=x%5;
    if(p==4)p=3;
    t+=k*3+p;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(t%3==0)
        {
            cal(a[i],t);
        }
        else if(t%3==1)
        {
            if(a[i]<4)
            {
                if(a[i]>=1)t++;
                if(a[i]>=2)t++;
            }
            else
            {
                t+=2,a[i]-=4;
                cal(a[i],t);
            }
        }
        else
        {
            if(a[i]<3)
            {
                if(a[i]>=1)t++;
            }
            else
            {
                t+=1,a[i]-=3;
                cal(a[i],t);
            }
        }
        // cout<<t<<endl;
    }
    cout<<t<<endl;
    return 0;
}