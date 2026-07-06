#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int b[]={0,192,442,692,942};
// vector<int> a;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // for(int i=1;i<=1e6;i++)
    //     if((i*i%1000)*i%1000==888)
    //         a.push_back(i);
    // for(int i=0;i<(int)a.size();i++)
    //     cout<<a[i]<<" ";
    int t;cin>>t;
    while(t--)
    {
        int k;cin>>k;
        if(k<=4)cout<<b[k]<<endl;
        else cout<<(k-1)/4<<b[(k-1)%4+1]<<endl;
    }
    return 0;
}
/*

1       192     193
2       442     250
3       692     250
4       942     250
5       1192    250
6       1442    250
7       1692    250
8       1942    250
9       2192    250
10      2442    250
11      2692    250
12      2942    250
13      3192    250
14      3442    250
15      3692    250
16      3942    250
17      4192    250
18      4442    250
19      4692    250
20      4942    250
21      5192    250
22      5442    250
23      5692    250
24      5942    250
25      6192    250
26      6442    250
27      6692    250
28      6942    250
29      7192    250
30      7442    250
31      7692    250
32      7942    250
33      8192    250
34      8442    250
35      8692    250
36      8942    250
37      9192    250
38      9442    250
39      9692    250
40      9942    250

*/