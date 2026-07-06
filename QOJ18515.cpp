#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
int n,q,best,last;
vector<int> a;
char ask(int x)
{
    cout<<"? "<<a[x-1]<<endl;
    cout.flush();
    char c;
    cin>>c;
    return c;
}
void answer(int x)
{
    cout<<"! "<<a[x-1]<<endl;
    cout.flush();
    exit(0);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>q;
    a.resize(n);
    for(int i=0;i<n;i++)
        a[i]=i+1;
    shuffle(a.begin(),a.end(),mt19937(chrono::steady_clock::now().time_since_epoch().count()));
    ask(1);
    best=1;
    last=1;
    for(int i=2;i<=n;i++)
    {
        char c=ask(i);
        if(c=='<')
            last=i;
        else if(c=='>')
        {
            int x=best;
            char d=ask(best);
            if(d=='<')
                best=i;
            last=x;
        }
        else last=i;
    }
    answer(best);
    return 0;
}
