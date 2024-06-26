#include <cstdio>
const int CLK_TCK = 100;
int main() {
	int c1, c2;
	scanf("%d %d", &c1, &c2);
	int res = c2 - c1;
	if(res % CLK_TCK >= 50) {
		res = res / CLK_TCK + 1;
	} else {
		res = res / CLK_TCK;
	}
	int h = res / 3600;
	int m = res % 3600 /60;
	int s = res % 3600 % 60;
	printf("%02d:%02d:%02d", h, m, s);
	return 0;
}
