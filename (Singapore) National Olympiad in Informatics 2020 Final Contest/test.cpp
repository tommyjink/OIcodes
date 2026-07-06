#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<long long>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<long long> tails;
    for(long long x:a){
        long long y = -x;
        auto it = lower_bound(tails.begin(), tails.end(), y);
        if(it == tails.end()) tails.push_back(y);
        else *it = y;
    }
    cout << tails.size() << "\n";
    return 0;
}