#include<bits/stdc++.h>
using namespace std;

const int N=1000000+5;

int n;
int px[N],py[N],sel[N],alive[N];
int ctop[N],cbot[N],ccnt[N];
vector<int> row[N],extra[N],used,bad;

inline bool cmpx(int a,int b){
    return px[a]<px[b];
}

inline int first_alive(int r){
    vector<int> &v=row[r];
    for(int i=0;i<(int)v.size();i++)
        if(alive[v[i]])return v[i];
    return 0;
}

inline int last_alive(int r){
    vector<int> &v=row[r];
    for(int i=(int)v.size()-1;i>=0;i--)
        if(alive[v[i]])return v[i];
    return 0;
}

inline void choose(int id){
    if(!id||sel[id])return;
    sel[id]=1;
    int c=px[id];
    if(ccnt[c]==0){
        ctop[c]=cbot[c]=id;
    }
    else if(ccnt[c]==1){
        int t=ctop[c];
        if(py[id]>py[t])ctop[c]=id;
        else cbot[c]=id;
    }
    else{
        if(py[id]>py[ctop[c]]){
            extra[c].push_back(ctop[c]);
            ctop[c]=id;
        }
        else if(py[id]<py[cbot[c]]){
            extra[c].push_back(cbot[c]);
            cbot[c]=id;
        }
        else extra[c].push_back(id);
    }
    ccnt[c]++;
    if(ccnt[c]>2)bad.push_back(c);
}

inline void erase_point(int id){
    if(!sel[id])return;
    sel[id]=0;

    int c=px[id];
    ccnt[c]--;
    if(ccnt[c]>2)bad.push_back(c);

    int r=py[id];
    int L=first_alive(r),R=last_alive(r);

    if(id==L){
        alive[id]=0;
        choose(first_alive(r));
    }
    else if(id==R){
        alive[id]=0;
        choose(last_alive(r));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    used.reserve(n);
    bad.reserve(n);

    for(int i=1;i<=n;i++){
        cin>>px[i]>>py[i];
        alive[i]=1;
        if(row[py[i]].empty())used.push_back(py[i]);
        row[py[i]].push_back(i);
    }

    for(int i=0;i<(int)used.size();i++){
        int r=used[i];
        vector<int> &v=row[r];
        sort(v.begin(),v.end(),cmpx);
        choose(v.front());
        if(v.size()>1)choose(v.back());
    }

    for(int i=0;i<(int)bad.size();i++){
        int c=bad[i];
        while(ccnt[c]>2){
            while(!extra[c].empty()&&!sel[extra[c].back()])extra[c].pop_back();
            if(extra[c].empty())break;
            int id=extra[c].back();
            extra[c].pop_back();
            erase_point(id);
        }
    }

    for(int i=1;i<=n;i++)cout<<(sel[i]?'1':'0');
    cout<<"\n";
    return 0;
}
