#include<bits/stdc++.h>

namespace IO{
	inline char getchar(){
		static const int maxbuf=65536;
		static char ibuf[maxbuf+1],*cur=ibuf+maxbuf;
	    return (cur==ibuf+maxbuf)?(fread(cur=ibuf,1,maxbuf,stdin),*cur++):*cur++;
	}
	void read(int &x){
		x=0;
		char t=getchar();
		while(!isdigit(t))t=getchar();
		while(isdigit(t))x=x*10+t-'0',t=getchar();
		return;
	}
}

using IO::read;