#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int mp[5][5];
int check()
{
    int res=0;
    for(int i=1;i<=3;i++)
        if(mp[i][1]==mp[i][2]&&mp[i][2]==mp[i][3]&&mp[i][1]==1)
            res++;
    for(int i=1;i<=3;i++)
        if(mp[1][i]==mp[2][i]&&mp[2][i]==mp[3][i]&&mp[1][i]==1)
            res++;
    if(mp[1][1]==mp[2][2]&&mp[2][2]==mp[3][3]&&mp[1][1]==1)
        res++;
    if(mp[1][3]==mp[2][2]&&mp[2][2]==mp[3][1]&&mp[1][3]==1)
        res++;
    return res;
}
pair<int,int> cal()
{
    int tx,ty;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(mp[i][j])continue;
            tx=i,ty=j;
            mp[i][j]=1;
            int tt=0;
            for(int ii=1;ii<=3;ii++)
                for(int jj=1;jj<=3;jj++)
                {
                    if(mp[ii][jj])continue;
                    mp[ii][jj]=1;
                    if(check())tt++;
                    mp[ii][jj]=0;
                }
            mp[i][j]=0;
            if(tt>1||check())
                return make_pair(i,j);
        }
    }
    return make_pair(tx,ty);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x,y,cnt=1;
    while(cin>>x&&cin>>y&&cnt<=9)
    {
        mp[x][y]=1;
        pair<int,int> res=cal();
        cout.flush()<<res.first<<" "<<res.second<<endl;
        mp[res.first][res.second]=2;
        cnt++;
    }
    return 0;
}