#include<stdio.h>
char s[1001];
int main(){
	int T,N,M,K,Q;
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d%d %s",&N,&M,&K,&Q,s);
		if(N==K&&M==K){
			for(int i=0;i<Q;++i)puts("1 1");
		}else if(N==K){
			for(int i=0,p=0;i<Q;++i)
				if(s[i]=='H'){
					printf("%d 1\n",++p);
					if(p==N)p=0;
				}else printf("1 %d\n",M);
		}else if(M==K){
			for(int i=0,p=0;i<Q;++i)
				if(s[i]=='V'){
					printf("1 %d\n",++p);
					if(p==M)p=0;
				}else printf("%d 1\n",N);
		}else{
			int x=N,y=M,p=K,q=K;
			for(int i=0;i<Q;++i)
				if(s[i]=='H'){
					printf("%d 1\n",x--);
					if(!x){
						if(y<=K)q=y,y=M,x=K;
						else x=N;
					}else if(x==K)x=p,p=K;
				}else{
					printf("1 %d\n",y--);
					if(!y){
						if(x<=K)p=x,x=N,y=K;
						else y=M;
					}else if(y==K)y=q,q=K;
				}
		}
	}
	return 0;
}
