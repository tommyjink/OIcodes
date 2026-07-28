#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int a[N],b[N],tag[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    int n=5;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        while(!a[i]||tag[a[i]])a[i]=a[i-1]+3+rand()%3;
        tag[a[i]]=1;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        while(!b[i]||tag[b[i]]||b[i]>=a[i])b[i]=a[i]-rand()%a[i];
        tag[b[i]]=1;
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int q=5;
    cout<<q<<endl;
    for(int i=1;i<=q;i++)
    {
        int l=rand()%n+1,r=rand()%n+1;
        if(l>r)swap(l,r);
        if(l==r&&l>1)l--;
        if(l==r&&r<n)r++;
        cout<<l<<" "<<r<<endl;
    }
    
    return 0;
}