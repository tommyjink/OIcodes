
        //     for(int j=0;j<=siz[v];j++)
        //         f[x][i+j][0]=min(f[x][i+j][0],f[x][i][0]+f[v][j][0]+hp[v]),
        //         f[x][i+j][0]=min(f[x][i+j][0],f[x][i][1]+f[v][j][0]),
        //         f[x][i+j][0]=min(f[x][i+j][0],f[x][i][0]+f[v][j][1]),
        //         f[x][i+j][0]=min(f[x][i+j][0],f[x][i][1]+f[v][j][1]),
        // siz[x]+=siz[v];