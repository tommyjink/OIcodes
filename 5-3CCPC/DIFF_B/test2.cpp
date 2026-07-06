#include<bits/stdc++.h>
using namespace std;
struct tagy{
    int gongcid,wnum;
    bool operator < (const tagy &x) const {
        return (wnum==x.wnum) ? gongcid<x.gongcid : wnum<x.wnum;
    }//注意这里的小于号重载
    tagy(int G,int W){
        gongcid=G,wnum=W;
    }
};
//构建一个标签结构体，分别记录各个工程序号及需求员工数量。
struct rwd{
    int kd,nm;
    rwd(int K,int N){
        kd=K,nm=N;
    }
};
//构建一个奖励结构体，用于在处理可实施工程时候更新员工数量。
int n,m,tn1,tn2,ans;
int cnt[500005];//记录每个工程的待满足需求量
unordered_map<int,int> ar; //记录每种员工目前的数量
stack<int> s;//维护目前可实施的全部工程
map<int,set<tagy> > tgm; 
vector<rwd> v[500005];
int main(){
    freopen("test.in","r",stdin);
    freopen("test2.out","w",stdout);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&tn1,&tn2);
        ar[tn1]=tn2;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&n);
        int t=0;
        while(n--){
            scanf("%d%d",&tn1,&tn2);
            if(ar[tn1]>=tn2) continue; //若已满足，则忽略。
            tgm[tn1].insert(tagy(i,tn2));
            t++;
        }
        if(!t) s.push(i);
        cnt[i]=t;
        scanf("%d",&n);
        while(n--){
            scanf("%d%d",&tn1,&tn2);
            v[i].push_back(rwd(tn1,tn2));
        }
    }
    while(s.size()){
        ans++; n=s.top(); s.pop();
        for(int i=0;i<v[n].size();i++){
            ar[v[n][i].kd]+=v[n][i].nm;
            while(1){
            	if(tgm[v[n][i].kd].size()==0) break; 
                set<tagy>::iterator IT;
                IT=tgm[v[n][i].kd].begin();
                if((IT->wnum) > ar[v[n][i].kd]) break;
                cnt[IT->gongcid]--;
                if(cnt[IT->gongcid]==0) s.push(IT->gongcid);
                tgm[v[n][i].kd].erase(IT);
            }
        }
    }
    cout<<ans;
    return 0;
}
