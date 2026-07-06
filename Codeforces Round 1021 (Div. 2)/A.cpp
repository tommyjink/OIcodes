#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int v[20]={0},vis[20]={0},ans[20]={0};
        cin>>s;
        for(int i=0;i<10;i++)
            v[i]=(s[i]-'0');
        for(int i=9;i>=0;i--)
        {
            int tmp=-1;
            for(int j=0;j<=9;j++)
            {
                if(vis[j])continue;
                if(v[j]>=i&&(tmp==-1||v[j]<v[tmp]))
                    tmp=j;
            }
            if(tmp!=-1)
            {
                ans[i]=v[tmp];
                vis[tmp]=true;
            }
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
/*
9988776655

9876556789


4
9999999999
9988776655
9988776650
9899999999

9999999999
9876556789
9876567890
9899999999

*/