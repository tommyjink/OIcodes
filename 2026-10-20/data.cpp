#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
int rd(){return rand()%120;}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cout<<"1"<<endl;
    int n=10,x=rd(),y=rd();
    cout<<n<<" "<<x<<" "<<y<<endl;
    vector<pii> V;
    for(int i=1;i<=n;i++)
        V.push_back({rd(),rd()});
    sort(V.begin(),V.end());
    for(auto [x,y]:V)
        cout<<x<<" "<<y<<endl;
    return 0;
}