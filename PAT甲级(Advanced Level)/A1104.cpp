#include <cstdio>
int main() {
	int n;
	scanf("%d", &n);
	double v, res = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lf", &v);
		res += v * i * (n + 1 - i);
	}
	printf("%.2f\n", res);
	return 0;
}
