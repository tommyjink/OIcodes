#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++)
            for(int k=1;k<=6;k++)
            {
                int x=0,y=0;
                if(i==1||i==4)x+=i;
                else y+=i;
                if(j==1||j==4)x+=j;
                else y+=j;
                if(k==1||k==4)x+=k;
                else y+=k;
                if(x==a&&y==b)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
    cout<<"No"<<endl;
    return 0;
}