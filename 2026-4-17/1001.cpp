#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=100;
int n,a[N],sum=0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
        if(s[i]=='#')a[i+1]=1;
        else a[i+1]=0;
    for(int i=1;i<=n;i++)sum+=a[i];
    int cnt=0;
    while(sum)
    {
        cnt++;
        a[sum]=1-a[sum];
        sum=0;
        for(int i=1;i<=n;i++)
            sum+=a[i];
        for(int i=1;i<=n;i++)
            if(a[i])cout<<'#';
            else cout<<'.';
        cout<<"    ("<<cnt<<")"<<endl;
    }
    return 0;
}
/*
#.#.##...###......#.#...##

......#..#.....#

*/