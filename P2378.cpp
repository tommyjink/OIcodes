#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
char s[1000];
int a,b,n,cntx=0,cnty=0,c,d;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='x')cntx++;
        if(s[i]=='-'||s[i]=='+')cnty++;
    }
    if(cntx==1&&cnty==0)
    {
        printf("x^2");
        return 0;
    }
    else if(cntx==1&&cnty==1)
        sscanf(s,"x^2%lld",&b);
    else if(cntx==2&&cnty==2)
    {
        sscanf(s,"x^2%lldx%lld",&a,&b);
        if(a==0)a=1;
    }
    else if(cntx==2&&cnty==1)
    {
        sscanf(s,"x^2%lldx",&a);
        if(a==0)a=1;
        if(a>=1)printf("(x+%lld)x",a);
        else    printf("x(x%lld)",a);
        return 0;
    }
    // cout<<a<<" "<<b<<endl;
    for(c=1;c*c<=abs(b);c++)
    {
        if(c==0)continue;
        if(b%c)continue;
        d=b/c;
        if(c+d==a)
        {
            if(c<d)
                swap(c,d);
            if(c==d)
            {
                if(c<0)
                    printf("(x%lld)^2",c);
                else    printf("(x+%lld)^2",c);
                return 0;
            }
            if(c<0) printf("(x%lld)",c);
            else printf("(x+%lld)",c);
            if(d<0) printf("(x%lld)",d);
            else printf("(x+%lld)",d);
            return 0;
        }
    }
    for(c=-1;c*c<=abs(b);c--)
    {
        if(c==0)continue;
        if(b%c)continue;
        d=b/c;
        if(c+d==a)
        {
            if(c<d)
                swap(c,d);
            if(c==d)
            {
                if(c<0)
                    printf("(x%lld)^2",c);
                else    printf("(x+%lld)^2",c);
                return 0;
            }
            if(c<0) printf("(x%lld)",c);
            else printf("(x+%lld)",c);
            if(d<0) printf("(x%lld)",d);
            else printf("(x+%lld)",d);
            return 0;
        }
    }
    // cout<<a<<" "<<b<<endl;
    return 0;
}
/*
x^2+x+4
x^2
*/