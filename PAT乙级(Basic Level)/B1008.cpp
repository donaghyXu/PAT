#include <cstdio>
int a[105];	//定义一个数组a 
int main() {
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);
	m = m % n;	//如果m大于n，就取余数 
	//输入n个整数 
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = n - m; i < n; i++) {
		printf("%d", a[i]);
		cnt++;	//统计输出个数 
		if(cnt < n) printf(" ");	//如果输出的个数小于n，则要输出空格，下同 
	}
	
	for(int i = 0; i < (n - m); i++) {
		printf("%d", a[i]);
		cnt++;
		if(cnt < n) printf(" "); 
	} 
	return 0;
} 
