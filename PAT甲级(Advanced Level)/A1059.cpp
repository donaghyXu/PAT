#include <cstdio>
#include <math.h>
const int maxn = 100010;
bool isPrime(int n) {
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}
int prime[maxn], pNum = 0;
void findPrime() {
	for(int i = 1; i < maxn; i++) {
		if(isPrime(i) == true) {
			prime[pNum++] = i;
		}
	}
}
struct member{
	int x, count;
}mem[10];
int main() {
	findPrime();
	int n, num = 0;
	scanf("%d", &n);
	if(n == 1) printf("1=1");
	else {
		printf("%d=", n);
		int sqr = (int)sqrt(1.0 * n);
		for(int i = 0; i < pNum && prime[i] <= sqr; i++) {
			if(n % prime[i] == 0) {
				mem[num].x = prime[i];
				mem[num].count = 0;
				while(n % prime[i] == 0) {
					mem[num].count++;
					n /= prime[i];
				}
				num++;
			}
			if(n == 1) break;	
		}
		if(n != 1) {
			mem[num].x = n;
			mem[num++].count = 1;
		}
		for(int i = 0; i < num; i++) {
			if(i > 0) printf("*");
			printf("%d", mem[i].x);
			if(mem[i].count > 1) {
				printf("^%d", mem[i].count);
			}
		}
	}
	
	return 0;
}
