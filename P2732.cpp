#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MOD = 1e9 + 7;
struct modint{ 
    int val=0;
    modint(int _val){
        val = (-MOD <= _val && _val <= MOD) ? _val : _val % MOD;
        if (val < 0) val += MOD;
    }
    modint operator
    + (const modint& other) const {
        return modint(val + other.val);
    }
    modint operator
    - (const modint& other) const {
        return modint(val - other.val);
    }
    modint operator
    * (const modint& other) const {
        return modint(val * other.val);
    }
    modint operator
    / (const modint& other) const {
        return modint(val) * modint(other.val).inv();
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}