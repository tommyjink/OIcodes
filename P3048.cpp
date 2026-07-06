#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,pos[20];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        pos[i]=i;
    for(int ii=1;ii<n;ii++)
    {
        for(int i=1;i<=k;i++)
        {
            if(pos[i]+1==pos[i+1])
                pos[i]=i;
            else 
            {
                pos[i]++;
                break;
            }
        }
    }
    for(int i=k;i>=1;i--)
    {
        // cout<<pos[i]<<" ";
        cout<<"1";
        for(int j=pos[i]-1;j>pos[i-1];j--)
            cout<<"0";
    }
    return 0;
}