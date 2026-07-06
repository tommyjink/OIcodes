#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int n,t,a[N],b[N];
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],b[i]=0;
        int cnt=0,tmp=0;
        while(!tmp)
        {
            tmp=1,cnt++;
            for(int i=1;i<=n-cnt+1;i++)
            {
                b[i]=b[i]|a[i-1+cnt];
                if(i!=1&&b[i]!=b[i-1])tmp=0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}