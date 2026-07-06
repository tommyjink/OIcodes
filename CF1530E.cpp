#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
string s;
int tot['z'+1];
void solve()
{
    cin>>s;
    sort(s.begin(),s.end());
    int n=s.length(),cnt=0,num=0;
    for(int i='a';i<='z';i++)
        tot[i]=0;
    for(int i=0;i<n;i++)
    {
        tot[(int)s[i]]++;
        if(i==0||s[i]!=s[i-1])num++;
        if(tot[(int)s[i]]==1)
            cnt++;
        if(tot[(int)s[i]]==2)
            cnt--;
    }
    // cout<<cnt<<endl;
    if(num==1)cout<<s<<endl;
    else if(cnt>0)
    {
        // cout<<"1"<<endl;
        int p=0;
        while(tot[(int)s[p]]!=1)p++;
        cout<<s[p];
        for(int i=0;i<n;i++)
            if(i!=p)cout<<s[i];
        cout<<endl;
    }
    else if(tot[(int)s[0]]==1)cout<<s<<endl;
    else if(tot[(int)s[0]]-2<=n-tot[(int)s[0]])
    {
        cout<<s[0]<<s[1];
        int l=2,r=2;
        while(s[r]==s[0])r++;
        while(s[l]==s[0]&&r<n)
        {
            cout<<s[r]<<s[l];
            l++,r++;
        }
        while(s[l]==s[0])cout<<s[l],l++;
        while(r<n)cout<<s[r],r++;
        cout<<endl;
    }
    else if(num>2)
    {
        cout<<s[0];
        int p=1,l=1;
        while(s[p]==s[0])p++;
        cout<<s[p];
        while(s[l]==s[0])cout<<s[0],l++;
        if(tot[s[p]]>1)
        {
            int r=p;
            while(r<n&&s[r]==s[p])r++;
            cout<<s[r],r++;
            p++;
            for(int i=p;i<n;i++)
                if(i!=r)cout<<s[i];
            cout<<endl;
        }
        else
        {
            while(p<n)cout<<s[p],p++;
            cout<<endl;
        }
    }
    else
    {
        int p=0;
        cout<<s[p];
        while(s[p]==s[0])p++;
        while(p<n)cout<<s[p],p++;
        p=1;
        while(s[p]==s[0])cout<<s[p],p++;
        cout<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/*
10000
iid
pppo
mprjooknrkjmkiqhp
wu
nwtprhh


tutttttttttttttttttvuuuuuuuuvvvv
tutttttttttttttttttuuuuuuuuvvvvv

*/