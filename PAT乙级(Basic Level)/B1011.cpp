#include <cstdio>
int main() {
	int t;
	scanf("%d", &t);
	long long a, b, c;
	for(int i = 1; i <= t; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if(a + b > c) printf("Case #%d: true\n", i);
		else printf("Case #%d: false\n", i);
	}
	return 0;
} 
