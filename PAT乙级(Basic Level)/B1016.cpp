#include <cstdio>
#include <cstring>
int main() {
	char a[15], b[15];
	int da, db;
	long long  pa = 0, pb = 0;
	scanf("%s %d %s %d", a, &da, b, &db);
	int alen = strlen(a);	//����a�ĳ��� 
	int blen = strlen(b);	//����b�ĳ���
	 
	for(int i = 0; i < alen; i++) {
		if(a[i] - '0' == da) pa = pa * 10 + da;	//����pa 
	}
	
	for(int i = 0; i < blen; i++) {
		if(b[i] - '0' == db) pb = pb * 10 + db; //����pb 
	}
	printf("%lld\n", pa + pb);
	return 0;
} 
