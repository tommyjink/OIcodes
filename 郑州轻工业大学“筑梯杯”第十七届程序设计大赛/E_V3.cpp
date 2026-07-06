#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int a[N],p=N/2,l=p,r=p,len=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;cin>>x;
            l--;
            a[l]=x;
            len++;
            if(len==1)
                p=l;
            else if(len%2==1)
            {
                p--;
                while(p>=l&&!a[p])p--;
            }
        }
        if(op==2)
        {
            int x;cin>>x;
            r++;
            a[r]=x;
            len++;
            if(len==1)
                p=r;
            else if(len%2==0)
            {
                p++;
                while(p<=r&&!a[p])p++;
            }
        }
        if(op==3)
        {
            cout<<a[p]<<endl;
            a[p]=0;
            len--;
            if(len==0)continue;
            if(len%2==0)
            {
                p++;
                while(p<=r&&!a[p])p++;
            }
            else
            {
                p--;
                while(p>=l&&!a[p])p--;
            }
        }
    }
    return 0;
}
/*
12
1 1
2 2
2 3
1 4
1 5
1 6
3
3
3
3
3
3
*/