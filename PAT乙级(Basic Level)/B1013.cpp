#include <cstdio>
#include <cmath>
int a[999999];	//设置一个比较大的数组 
int m, n;

//判断是否是素数 
bool isPrime(int n) {
	if(n == 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

//打表，将前N个素数存入数组 
void findPrime() {
	int cnt = 1;	//统计个数 
	for(int i = 1; i <= 999999; i++) {
		if(isPrime(i)) a[cnt++] = i;	//是素数，存入数组 
		if(cnt > n) break;
	}
}
int main() {
	int p = 1;	//控制每10个换行的格式 
	scanf("%d %d", &m, &n);
	findPrime();	//打表
	
	//打印第m~n个素数 
	for(int i = m; i <= n; i++) {
		printf("%d", a[i]);
		if(p % 10 != 0 && i < n) printf(" ");	//p不到10的倍数且不是最后一个输出空格 
		else printf("\n");
		p++;
	}
	return 0;
} 
