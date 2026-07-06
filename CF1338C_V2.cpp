#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6;
int tag[N];
vector<int> a,b;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q=1000;
    while(q--)
    {
        int p=1;
        while(tag[p])p++;
        a.push_back(p);
        tag[p]=true;
        int k=1;
        while(tag[k]||tag[(k^p)])k++;
        tag[k]=true;
        tag[k^p]=true;
        a.push_back(k);
        a.push_back(k^p);
    }
    for(int i=0;i+2<a.size();i+=3)
    {
        cout<<a[i]<<" "<<a[i+1]<<" "<<a[i+2]<<endl;
        b.push_back(a[i]);
    }
    cout<<endl;
    for(int i=1;i<b.size();i++)
        if(b[i]!=b[i-1]+1)
            cout<<b[i-1]<<" "<<b[i]<<endl;
    // for(auto i:a)cout<<i<<" ";
    return 0;
}