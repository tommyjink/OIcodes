//题目大意： 有n块石头，每块石头有一个序号和一个魔力值，你可以使用任意数量的石头，但你使用的石头中任意几块元素序号异或起来不能为0，求最大总魔力值。
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4,M=63;
int n,ans=0,p[M];
struct node
{
    int x,y;
}a[N];
bool cmp(node x,node y)
{
    return x.y>y.y;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        int x=a[i].x;
        for(int j=M-1;j>=0;j--)
        {
            if((x>>j)&1)
            {
                if(!p[j])
                {
                    p[j]=x;
                    break;
                }
                else
                    x^=p[j];
            }
        }
        if(x)
            ans+=a[i].y;
    }
    cout<<ans<<endl;
    return 0;
}