#include<bits/stdc++.h>
#define LL long long
const int SZ = 3e3+10, BASE = 1e3+10;
LL A[SZ][SZ], B[SZ][SZ], C[SZ][SZ], D[SZ][SZ], E[SZ][SZ], F[SZ][SZ], G[SZ][SZ];
int main() {
    int h, w, t; scanf("%d%d%d", &h, &w, &t);
    for(int y=1;y<=h;++y) for(int x=1;x<=w;++x) scanf("%lld", &G[y][x]);
    for(int z=0;z<t;++z){
        int u,v,l; scanf("%d%d%d",&u,&v,&l); --l; 
        u+=BASE; v+=BASE;
        C[u-l][v-l]++;
        A[u-l+1][v-l+1]+=2;
        A[u+1][v+1]-=2;
        A[u+2][v+2]-=2;
        A[u+l+2][v+l+2]+=2;
        C[u+l+2][v+l+2]--;
        D[u-l][v+l+1]--;
        B[u-l+1][v+l]-=2;
        B[u+1][v]+=2;
        B[u+2][v-1]+=2;
        B[u+l+2][v-l-1]-=2;
        D[u+l+2][v-l-1]++;
    }
    for(int i=1;i<SZ;++i) for(int j=1;j<SZ;++j) A[i][j]+=A[i-1][j-1];
    for(int i=1;i<SZ;++i) for(int j=1;j<SZ;++j) C[i][j]=C[i][j]+A[i][j]+C[i-1][j-1];
    for(int i=1;i<SZ;++i) for(int j=SZ-2;j>=0;--j) B[i][j]+=B[i-1][j+1];
    for(int i=1;i<SZ;++i) for(int j=SZ-2;j>=0;--j) D[i][j]=D[i][j]+B[i][j]+D[i-1][j+1];
    for(int i=0;i<SZ;++i) for(int j=0;j<SZ;++j) E[i][j]=C[i][j]+D[i][j];
    for(int i=1;i<SZ;++i) for(int j=1;j<SZ;++j) E[i][j]+=E[i-1][j]+E[i][j-1]-E[i-1][j-1];
    for(int y=1;y<=h;++y){
        for(int x=1;x<=w;++x){
            LL v=G[y][x]-E[y+BASE][x+BASE];
            if(v<0) v=0;
            printf("%lld%c",v,x==w?'\n':' ');
        }
    }
    return 0;
}
