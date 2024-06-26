#include <cstdio>
#include <cmath>
typedef long long LL;
int main() {
	LL n;
	scanf("%lld", &n);
	int sqr = (int)sqrt(1.0 * n);
	int resLen = 0, res;
	for(int i = 2; i <= sqr; i++) {
		int temp = 1, j = i;
		temp = temp * j;
		while(n % temp == 0) {
			j++;
			temp = temp * j;
		}
		if(j - i> resLen) {
			res = i;
			resLen = j - i;
		}
	}
	if(resLen == 0) printf("1\n%lld\n", n);
	else {
		printf("%d\n", resLen);
		for(int i = res; i < res + resLen; i++) {
			if(i == res) printf("%d", i);
			else printf("*%d", i);
		}
	}
	return 0;
}
