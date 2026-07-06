#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pbb pair<bool,bool>
using namespace std;
int n,m;
string s;
string s1=" ",s2=" ";
bool check1()
{
    int p1=1,p2=m+2;
    while(p1<m+1&&p2<n&&s[p1]==s[p2])p1++,p2++;
    p1--,p2--;
    int l1=m+1,l2=n;
    while(l1>0&&l2>0&&s[l1]==s[l2])l1--,l2--;
    l1++,l2++;
    // cout<<p1<<","<<p2<<","<<l1<<","<<l2<<endl;
    return p2+1>=l2;
}   
bool check2()
{
    int p1=1,p2=m+1;
    while(p1<m+1&&p2<n&&s[p1]==s[p2])p1++,p2++;
    p1--,p2--;
    int l1=m,l2=n;
    while(l1>0&&l2>0&&s[l1]==s[l2])l1--,l2--;
    l1++,l2++;
    // cout<<p1<<","<<p2<<","<<l1<<","<<l2<<endl;
    return p1+1>=l1;
}
signed main()
{
    freopen("friend.in","r",stdin);
    freopen("friend.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;s=" "+s;
    if(n%2==0)
    {
        cout<<"NOT POSSIBLE"<<endl;
        return 0;
    }
    m=n/2;
    for(int i=1;i<=m;i++)
        s1.push_back(s[i]),s2.push_back(s[i+n-m]);
    if(s1==s2)
    {
        for(int i=1;i<=m;i++)
            cout<<s1[i];
        return 0;
    }
    bool res1=check1();
    bool res2=check2();
    // cout<<s1;
    // cout<<s1[1]<<endl;
    if(res1&&res2)cout<<"NOT UNIQUE"<<endl;
    else if(res2)for(int i=1;i<=m;i++)cout<<s1[i];
    else if(res1)for(int i=1;i<=m;i++)cout<<s2[i];
    else cout<<"NOT POSSIBLE"<<endl;
    // cout<<s1<<endl<<s2<<endl;
    return 0;
}
/*

【样例输入】
7
ABCXABC
【样例输出】
ABC



7
ABCABCD

7
ABXCABC

7
ABCABXC

7
ABCDABC

7
ABDCABB

7
ACCACCC
*/