#include <cstdio>
#include <cstring>
int main() {
	char a[15], b[15];
	int da, db;
	long long  pa = 0, pb = 0;
	scanf("%s %d %s %d", a, &da, b, &db);
	int alen = strlen(a);	//计算a的长度 
	int blen = strlen(b);	//计算b的长度
	 
	for(int i = 0; i < alen; i++) {
		if(a[i] - '0' == da) pa = pa * 10 + da;	//计算pa 
	}
	
	for(int i = 0; i < blen; i++) {
		if(b[i] - '0' == db) pb = pb * 10 + db; //计算pb 
	}
	printf("%lld\n", pa + pb);
	return 0;
} 
