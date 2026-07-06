#include <bits/stdc++.h>
#define int __int128
#define endl "\n"
using namespace std;
map<int, pair<int, int> > mp;
__int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        f = -1, ch = getchar();
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    return f * x;
}
void print(__int128 x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}
int lcm(int x, int y)
{
    return (x / gcd(x, y)) * y;
}
int sqrt(int x)
{
    int l=1,r=x;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(mid*mid<x)l=mid+1;
        else r=mid;
    }
    return l;
}
signed main()
{
    freopen("operation.in", "r", stdin);
    freopen("operation.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int j = 20; j >= 3; j--)
    {
        for (int i = 1; i <= 2e7; i++)
        {
            int res=1;
            for(int k=i;k<j+i;k++)
                res=lcm(res,k);
            if(res>1e19)break;
            if (!mp.count(res))
                mp[res] = make_pair(i, i + j - 1);
        }
    }
    int T;
    T=read();
    while (T--)
    {
        int x;
        x=read();
        int tmp=sqrt(x);
        if(mp.count(x))
        {
            print(mp[x].first);
            cout<<" ";
            print(mp[x].second);
            cout<<endl;
        }
        else if(tmp*(tmp+1)==x)
        {
            print(tmp);
            cout<<" ";
            print(tmp+1);
            cout<<endl;
        }
        else
        {
            print(x);
            cout<<" ";
            print(x);
            cout<<endl;
        }
    }
    return 0;
}