#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int x,y,a[10][10],vis[20];
bool legal(int x)
{
    return x>=1&&x<=16;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>x>>y;
    for(a[1][1]=1;a[1][1]<=16;a[1][1]++)
    {
        for(a[1][2]=1;a[1][2]<=16;a[1][2]++)
        {
            for(a[1][3]=1;a[1][3]<=16;a[1][3]++)
            {
                a[1][4]=34-a[1][1]-a[1][2]-a[1][3];
                if(!legal(a[1][4]))continue;
                for(a[2][1]=1;a[2][1]<=16;a[2][1]++)
                {
                    a[2][2]=34-a[1][1]-a[1][2]-a[2][1];
                    if(!legal(a[2][2]))continue;
                    for(a[2][3]=1;a[2][3]<=16;a[2][3]++)
                    {
                        a[2][4]=34-a[2][1]-a[2][2]-a[2][3];
                        if(!legal(a[2][4]))continue;
                        for(a[3][1]=1;a[3][1]<=16;a[3][1]++)
                        {
                            a[4][1]=34-a[1][1]-a[2][1]-a[3][1];
                            if(!legal(a[4][1]))continue;
                            a[3][2]=34-a[1][4]-a[2][3]-a[4][1];
                            if(!legal(a[3][2]))continue;
                            a[4][2]=34-a[3][1]-a[3][2]-a[4][1];
                            if(!legal(a[4][2]))continue;
                            a[3][3]=34-a[2][2]-a[2][3]-a[3][2];
                            if(!legal(a[3][3]))continue;
                            a[3][4]=34-a[3][1]-a[3][2]-a[3][3];
                            if(!legal(a[3][4]))continue;
                            a[4][3]=34-a[1][3]-a[2][3]-a[3][3];
                            if(!legal(a[4][3]))continue;
                            a[4][4]=34-a[3][3]-a[3][4]-a[4][3];
                            if(!legal(a[4][4]))continue;
                            if(a[4][1]+a[4][2]+a[4][3]+a[4][4]!=34)continue;
                            if(a[1][4]+a[2][4]+a[3][4]+a[4][4]!=34)continue;
                            if(a[1][1]+a[2][2]+a[3][3]+a[4][4]!=34)continue;
                            if(a[1][1]+a[1][4]+a[4][1]+a[4][4]!=34)continue;
                            if(a[x][y]!=1)continue;
                            int tag=0;
                            memset(vis,0,sizeof(vis));
                            for(int i=1;i<=4;i++)
                                for(int j=1;j<=4;j++)
                                {
                                    if(vis[a[i][j]])tag=true;
                                    vis[a[i][j]]=true;
                                }
                            if(tag)continue;
                            for(int i=1;i<=4;i++)
                            {
                                for(int j=1;j<=4;j++)
                                {
                                    cout<<a[i][j]<<" ";
                                }
                                cout<<endl;
                            }
                            cout<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}