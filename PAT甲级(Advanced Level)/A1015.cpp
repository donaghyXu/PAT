#include <cstdio>
#include <math.h>
const int maxn = 100010;
int a[maxn];
bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int tenToNToTen(int num, int n) {
	int count = 0, res = 0, s = 1;
	while(num != 0) {
		a[count++] = num % n;
		num /= n;
	}
	for(int i = count - 1; i >= 0; i--) {
		res = res + a[i] * s;
		s *= n;
	}
	return res;
}


int main() {
	int n, radix;
	while(scanf("%d", &n) != EOF) {
		if(n < 0) break;
		scanf("%d", &radix);
		if(isPrime(n) == false)	printf("No\n");
		else if(isPrime(tenToNToTen(n, radix)) == true) {
			printf("Yes\n");
		} else printf("No\n");
	}
	return 0;
}
