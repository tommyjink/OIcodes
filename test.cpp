#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,sl,sr;
struct node{
    int v,l,r,mp,id;
}a[1000001];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        stack<char>st;
        for(int j=0;j<s.size();j++){
            if(s[j]=='(')st.push(s[j]);
            else{
                if(!st.empty()&&st.top()=='(')st.pop();
                else st.push(s[j]);
            }
        }
        int cur=0;
        while(!st.empty()){
            char c=st.top();
            st.pop();
            if(c=='(')a[i].l++;
            else a[i].r++;
        }
        for(int j=0;j<s.size();j++){
            if(s[j]=='(')cur++;
            else cur--;
            a[i].mp=min(a[i].mp,cur);
        }
        a[i].v=a[i].l-a[i].r,a[i].id=i;
        sl+=a[i].l,sr+=a[i].r;
    }
    if(sl!=sr){
        cout<<"impossible";
        return 0;
    }
    sort(a+1,a+n+1,[](const node&x,const node&y){
        if((x.r<=x.l)!=(y.r<=y.l))return x.r<=x.l;
        if(x.r<=x.l)return x.r<y.r;
        return x.l>y.l;
    });
    long long sum=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i].mp<0){
            cout<<"impossible";
            return 0;
        }
        sum+=a[i].v;
    }
    if(sum!=0){
        cout<<"impossible";
        return 0;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i].id<<endl;
    }
}