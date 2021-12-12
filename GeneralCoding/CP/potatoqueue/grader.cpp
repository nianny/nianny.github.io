#include "potatoqueue.h"
#include <cstdio>
#include <cstring>
char str[100];
int h,n;
int main(){
	init();
	while(scanf("%s",str)!=EOF){
		if(strcmp(str,"join")==0){
			scanf("%d\n",&h);
			join(h);
		}
		else if(strcmp(str,"serve")==0) serve();
		else{
			scanf("%d\n",&n);
			printf("%d\n",query(n));
		}
	}
	return 0;
}
