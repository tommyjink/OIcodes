#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=20;
const int prime[]={1,2,3,5,7,11};
const int val[]={0,1,2,6,30,210,2310};
char s1[N],s2[N];
int n1,n2,tot1,tot2,a1[N],a2[N],res,ans[N];
void geta(int *a,char *s,int n)
{
    for(int i=1;i<=5;i+=1)
        if(n-(i-1)*2>=0)
            a[i]=s[n-(i-1)*2]-'0';
    if(n-9>=0)a[5]=10;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s1;
    for(n1=0;s1[n1]!='+';n1++);
    n1--;
    for(n2=0;n1+n2+2<strlen(s1);n2++)
        s2[n2]=s1[n1+n2+2];
    n2--;
    // cout<<n1<<" "<<n2<<endl;
    // cout<<s1<<" "<<s2<<endl;
    geta(a1,s1,n1);
    geta(a2,s2,n2);
    // for(int i=1;i<=5;i++)
    //     cout<<a1[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=5;i++)
    //     cout<<a2[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=5;i++)
        res+=a1[i]*val[i]+a2[i]*val[i];
    // cout<<res<<endl;
    for(int i=6;i>=1;i--)
        ans[i]=res/val[i],
        res-=ans[i]*val[i];
    bool tag=false;
    for(int i=6;i>=1;i--)
    {
        if(ans[i])
            tag=true;
        if(tag)
            cout<<ans[i];
        if(tag&&i>1)cout<<",";
    }
    if(!tag)cout<<"0";
    return 0;
}//1,0+2,1
//1,2,1,2,0+10,2,2,2,1