#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const int N=2e6+10,P=998244353;
int t,n,m,fac2[N],fac3[N];
int dis(int x,int y){return (y-x+2*n)%(2*n);}
int oppo(int x){return (x+n)%(2*n);}
vector<int> yes;
vector<pii> no;
void cal(vector<pii> &res,vector<pii> &v)
{
    if(v.empty())return;
    sort(v.begin(),v.end());
    int l=v[0].first,r=v[0].second;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first<=r+1)
            r=max(r,v[i].second);
        else
        {
            res.push_back({l,r});
            l=v[i].first,r=v[i].second;
        }
    }
    res.push_back({l,r});
}
int cnt0(int a,int b)
{
    int res=0;
    for(auto [l,r]:no)
    {
        res+=max(0ll,min(r+1,b)-max(l,a));
    }
    return res;
}
int cnt(int l,int r)
{
    if(l>=r)return 0;

    int M=2*n;

    while(l<0)
        l+=M,r+=M;

    while(l>=M)
        l-=M,r-=M;

    if(r<=M)
        return cnt0(l,r);

    return cnt0(l,M)+cnt0(0,r-M);
}
void solve()
{
    yes.clear();
    no.clear();
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(dis(x,y)==n)
        {
            no.push_back({x,x});
            no.push_back({y,y});
        }
        else
        {
            if(dis(x,y)>n)swap(x,y);
            int a=oppo(y),b=x;
            yes.push_back(a);
            yes.push_back(b);
            no.push_back({oppo(a),oppo(a)});
            no.push_back({oppo(b),oppo(b)});
            if(a<b){if(a+1<=b-1)no.push_back({a+1,b-1});}
            else 
            {
                if(a+1<2*n)no.push_back({a+1,2*n-1});
                if(b>0)no.push_back({0,b-1});
            }
        }
    }
    sort(yes.begin(),yes.end());
    yes.erase(unique(yes.begin(),yes.end()),yes.end());
    sort(no.begin(),no.end());
    vector<pii> tmp;
    cal(tmp,no);
    no=tmp;
    tmp.clear();
    int B=0,K=yes.size();
    for(auto [l,r]:no)
    {
        auto p=lower_bound(yes.begin(),yes.end(),l);
        if(p!=yes.end()&&*p<=r)
        {
            cout<<0<<endl;
            return;
        }
        B+=r-l+1;
        if(r<n)
            tmp.push_back({l,r});
        else if(l<n&&r>=n)
        {
            tmp.push_back({l,n-1});
            tmp.push_back({0,r-n});
        }
        else
            tmp.push_back({l-n,r-n});
    }
    vector<pii> tmp1;
    cal(tmp1,tmp);
    int U=0;
    for(auto [l,r]:tmp1)U+=r-l+1;
    int L=fac2[2*U-B-K]*fac3[n-U]%P;
    if(K==0)
    {
        int k=n-m;
        cout<<((fac3[k]-k*fac2[k]-1)%P+P)%P<<endl;
        return;
    }
    else
    {
        int lst=yes.back(),tag=0,a,b;
        for(int i:yes)
        {
            if((i-lst+2*n)%(2*n)>n)tag=1,a=lst,b=i;
            lst=i;
        }
        if(tag)
        {
            swap(a,b);
            if(b<a)b+=2*n;
            int C=n-K-cnt(a,a+n);
            int R=a-b+n-1-cnt(b-n+1,a);
            cout<<((L-fac2[C]-R*fac2[C-1]%P)%P+P)%P<<endl;
            return;
        }
        else
        {
            cout<<L<<endl;
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fac2[0]=fac3[0]=1;
    for(int i=1;i<N;i++)
        fac2[i]=fac2[i-1]*2%P,
        fac3[i]=fac3[i-1]*3%P;
    cin>>t;
    while(t--)solve();
    return 0;
}