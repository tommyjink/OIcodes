#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int INF=1e10;
vector<int> s;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string op;
        int x;
        cin>>op>>x;
        if(op[0]=='I')
            s.push_back(x);
        if(op[0]=='D')
            for(int j=0;j<(int)s.size();j++)
                if(s[j]==x)
                    s[j]=-INF;
        if(op[0]=='A')
            for(int j=0;j<(int)s.size();j++)
                if(s[j]!=-INF)
                    s[j]+=x;
        if(op[0]=='Q')
        {
            int res=0;
            for(int j=0;j<(int)s.size();j++)
                if(s[j]!=-INF&&(s[j]&(1ll<<(x))))
                    res++;
            cout<<res<<endl;
        }
        // for(int j=0;j<(int)s.size();j++)
        //     cout<<s[j]<<" ";
        // cout<<endl;
    }
    
    return 0;
}
/*
8
INS 1
QBIT 0
ADD 1
QBIT 0
QBIT 1
DEL 2
INS 1
QBIT 1


1
0
1
0
*/