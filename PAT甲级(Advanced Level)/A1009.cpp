#include <cstdio> 
const int maxn = 2001;
struct Poly{
	int exp;
	double coe;
}poly[1001];
int main() {
	int m, n, count = 0;
	double res[maxn] = {0.0};
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %lf", &poly[i].exp, &poly[i].coe);
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int exp;
		double coe;
		scanf("%d %lf", &exp, &coe);
		for(int j = 0; j < m; j++) {
			res[exp + poly[j].exp] += (coe * poly[j].coe);
			//printf("%d %.1f\n", exp + poly[j].exp, coe * poly[j].coe);
		}
	}
	
	for(int i = 0; i < maxn; i++) {
		if(res[i] != 0.0) count++;
	}
	printf("%d ", count);
	for(int i = maxn - 1; i >= 0; i--) {
		if(res[i] != 0.0) {
			printf("%d %.1f", i, res[i]);
			count--;
			if(count != 0.0) printf(" ");
		}
	}
	return 0;
}
