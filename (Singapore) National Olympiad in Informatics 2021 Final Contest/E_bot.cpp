#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=300005;
int n,k,d[N],s[N],f[N],rt[N];
pair<int,int> rg[N];
vector<int> ta,stj;
vector<pair<int,int> > td,ev;
priority_queue<pair<int,int> > pq;
set<int> st;
set<int>::iterator it,itl,itr;

int ql(int o,int p,int l,int r)
{
    if(o<0||!ta[o])return -1;
    if(l==r)return l<=p?l:-1;
    int t=-1;
    if((l+r)/2<p)t=ql(td[o].second,p,(l+r)/2+1,r);
    if(t!=-1)return t;
    return ql(td[o].first,p,l,(l+r)/2);
}

int qr(int o,int p,int l,int r)
{
    if(o<0||!ta[o])return -1;
    if(l==r)return l>=p?l:-1;
    int t=-1;
    if(p<(l+r)/2+1)t=qr(td[o].first,p,l,(l+r)/2);
    if(t!=-1)return t;
    return qr(td[o].second,p,(l+r)/2+1,r);
}

void upd(int o,int p,int v,int l,int r)
{
    if(l==r){ta[o]+=v;return;}
    int m=(l+r)>>1;
    if(p<=m)
    {
        if(td[o].first<0)
        {
            td[o].first=ta.size();
            ta.push_back(0);
            td.push_back({-1,-1});
        }
        else
        {
            ta.push_back(ta[td[o].first]);
            td.push_back(td[td[o].first]);
            td[o].first=ta.size()-1;
        }
        upd(td[o].first,p,v,l,m);
    }
    else
    {
        if(td[o].second<0)
        {
            td[o].second=ta.size();
            ta.push_back(0);
            td.push_back({-1,-1});
        }
        else
        {
            ta.push_back(ta[td[o].second]);
            td.push_back(td[td[o].second]);
            td[o].second=ta.size()-1;
        }
        upd(td[o].second,p,v,m+1,r);
    }
    ta[o]=(td[o].first>-1?ta[td[o].first]:0)+(td[o].second>-1?ta[td[o].second]:0);
}

pair<int,int> rng(int a,int b,int c)
{
    int l=0,r=k,j,x1,x2;
    pair<int,int> res={k,0};
    bool e0,ek;
    x1=((n-b-1)*s[b]-(n-c-1)*s[c]+0*(s[b]-s[c]))/(c-b);
    x2=((n-a-1)*s[a]-(n-b-1)*s[b]+0*(s[a]-s[b]))/(b-a);
    e0=x2<x1;
    x1=((n-b-1)*s[b]-(n-c-1)*s[c]+k*(s[b]-s[c]))/(c-b);
    x2=((n-a-1)*s[a]-(n-b-1)*s[b]+k*(s[a]-s[b]))/(b-a);
    ek=x2<x1;
    if(!e0&&!ek)return {-1,k+1};
    if(e0&&ek)return {k,0};
    if(!e0)
    {
        while(l<r)
        {
            j=(l+r)>>1;
            x1=((n-b-1)*s[b]-(n-c-1)*s[c]+j*(s[b]-s[c]))/(c-b);
            x2=((n-a-1)*s[a]-(n-b-1)*s[b]+j*(s[a]-s[b]))/(b-a);
            if(x2<x1)r=j;
            else l=j+1;
        }
        res.second=(l+r)>>1;
    }
    else
    {
        while(l<r)
        {
            j=(l+r+1)>>1;
            x1=((n-b-1)*s[b]-(n-c-1)*s[c]+j*(s[b]-s[c]))/(c-b);
            x2=((n-a-1)*s[a]-(n-b-1)*s[b]+j*(s[a]-s[b]))/(b-a);
            if(x2<x1)l=j;
            else r=j-1;
        }
        res.first=(l+r)>>1;
    }
    return res;
}

int cut(int a,int b)
{
    int l=k,r=n,m;
    while(l<r)
    {
        m=(l+r)>>1;
        if(f[a]-2*a*s[a]+2*a*s[m]<=f[b]-2*b*s[b]+2*b*s[m])r=m;
        else l=m+1;
    }
    return (l+r)>>1;
}

signed main()
{
    scanf("%lld%lld",&n,&k);
    --k;
    for(int i=0;i<n-1;i++)scanf("%lld",&d[i]),s[i+1]=s[i]+d[i];
    for(int i=0;i<n;i++)rg[i]={k,0};

    for(int i=k;i<n;i++)st.insert(i);
    for(int i=k+1;i<n-1;i++)
    {
        pair<int,int> t=rng(i+1,i,i-1);
        pq.push({-t.first,i});
    }
    while(!pq.empty())
    {
        int x=pq.top().second;
        if(pq.top().first<k&&st.find(x)!=st.end())
        {
            rg[x].first=-pq.top().first;
            pq.pop();
            st.erase(x);
            it=st.upper_bound(x);
            if(*it<n-1)
            {
                itl=itr=it;
                ++itl;--itr;
                pq.push({-rng(*itl,*it,*itr).first,*it});
            }
            --it;
            if(*it>k)
            {
                itl=itr=it;
                ++itl;--itr;
                pq.push({-rng(*itl,*it,*itr).first,*it});
            }
        }
        else pq.pop();
    }

    for(int i=k;i<n;i++)st.insert(i);
    for(int i=k+1;i<n-1;i++)
    {
        pair<int,int> t=rng(i+1,i,i-1);
        pq.push({t.second,i});
    }
    while(!pq.empty())
    {
        int x=pq.top().second;
        if(pq.top().first&&st.find(x)!=st.end())
        {
            rg[x].second=pq.top().first;
            pq.pop();
            st.erase(x);
            it=st.upper_bound(x);
            if(*it<n-1)
            {
                itl=itr=it;
                ++itl;--itr;
                pq.push({rng(*itl,*it,*itr).second,*it});
            }
            --it;
            if(*it>k)
            {
                itl=itr=it;
                ++itl;--itr;
                pq.push({rng(*itl,*it,*itr).second,*it});
            }
        }
        else pq.pop();
    }

    for(int i=k;i<n;i++)if(rg[i].first>=rg[i].second)
    {
        ev.push_back({rg[i].first,i});
        ev.push_back({rg[i].second-1,-i});
    }
    sort(ev.begin(),ev.end());

    for(int i=k,j=(int)ev.size()-1;i>=0;i--)
    {
        rt[i]=ta.size();
        ta.push_back(0);
        td.push_back({-1,-1});
        if(i<k)
        {
            ta[rt[i]]=ta[rt[i+1]];
            td[rt[i]]=td[rt[i+1]];
        }
        for(;j>-1&&i<=ev[j].first;j--)
        {
            if(ev[j].second>0)upd(rt[i],ev[j].second,1,0,n-1);
            else upd(rt[i],-ev[j].second,-1,0,n-1);
        }
    }

    int x=k,y=k,j=0,a,b,c,t,p1,p2;
    for(int i=k;i>=0;i--)
    {
        if(i<k)
        {
            a=f[stj[j]]+2*stj[j]*(s[x]-s[stj[j]])+2*(n-x-1)*(s[x]-s[i]);
            t=qr(rt[stj[j]],x+1,0,n-1);
            while(t>-1)
            {
                b=f[stj[j]]+2*stj[j]*(s[t]-s[stj[j]])+2*(n-t-1)*(s[t]-s[i]);
                if(a<b)break;
                x=t;
                a=f[stj[j]]+2*stj[j]*(s[x]-s[stj[j]])+2*(n-x-1)*(s[x]-s[i]);
                t=qr(rt[stj[j]],x+1,0,n-1);
            }
            while(j<(int)stj.size()-1)
            {
                y=qr(rt[stj[j+1]],y,0,n-1);
                a=f[stj[j+1]]+2*stj[j+1]*(s[y]-s[stj[j+1]])+2*(n-y-1)*(s[y]-s[i]);
                t=qr(rt[stj[j+1]],y+1,0,n-1);
                while(t>-1)
                {
                    b=f[stj[j+1]]+2*stj[j+1]*(s[t]-s[stj[j+1]])+2*(n-t-1)*(s[t]-s[i]);
                    if(a<b)break;
                    y=t;
                    a=f[stj[j+1]]+2*stj[j+1]*(s[y]-s[stj[j+1]])+2*(n-y-1)*(s[y]-s[i]);
                    t=qr(rt[stj[j+1]],y+1,0,n-1);
                }
                a=f[stj[j]]+2*stj[j]*(s[x]-s[stj[j]])+2*(n-x-1)*(s[x]-s[i]);
                b=f[stj[j+1]]+2*stj[j+1]*(s[y]-s[stj[j+1]])+2*(n-y-1)*(s[y]-s[i]);
                if(a<b)break;
                ++j;
                x=y;
            }
            f[i]=f[stj[j]]+2*stj[j]*(s[x]-s[stj[j]])+2*(n-x-1)*(s[x]-s[i]);
        }

        if(!stj.empty()&&f[stj.back()]-2*stj.back()*s[stj.back()]+2*stj.back()*s[n-1]<=f[i]-2*i*s[i]+2*i*s[n-1])continue;
        while(stj.size()>1)
        {
            a=qr(rt[i],cut(i,stj.back()),0,n-1);
            b=cut(stj.back(),stj[stj.size()-2]);
            c=ql(rt[stj[stj.size()-2]],b-1,0,n-1);
            b=qr(rt[stj.back()],b,0,n-1);
            if(a<=b){stj.pop_back();continue;}
            p1=((n-b-1)*s[b]-(n-c-1)*s[c]+stj.back()*s[b]-stj[stj.size()-2]*s[c]+f[stj.back()]/2-f[stj[stj.size()-2]]/2-stj.back()*s[stj.back()]+stj[stj.size()-2]*s[stj[stj.size()-2]])/(c-b);
            p2=((n-a-1)*s[a]-(n-b-1)*s[b]+i*s[a]-stj.back()*s[b]+f[i]/2-f[stj.back()]/2-i*s[i]+stj.back()*s[stj.back()])/(b-a);
            if(p1<=p2)stj.pop_back();
            else break;
        }
        stj.push_back(i);
    }

    int sum=0;
    for(int i=0;i<n;i++)sum+=abs(s[k]-s[i]);
    printf("%lld",f[0]+sum);
    return 0;
}
