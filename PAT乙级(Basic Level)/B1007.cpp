#include <cstdio>
#include <cmath>
 
//判断n是否为素数 
bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
} 

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	//判断有多少对素数对 
	for(int i = 3; i + 2 <= n; i += 2) {
		if(isPrime(i) && isPrime(i + 2)) cnt++;
	}
	printf("%d", cnt);
	return 0;
} 
