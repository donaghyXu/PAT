#include <cstdio>
int main() {
	int a[3];
	double n;
	double res = 1.0, max;
	char s[3] = {'W','T','L'};
	for(int i = 0; i < 3; i++) {
		max = 0.0; 
		for(int j = 0; j < 3; j++) {
			scanf("%lf", &n);
			if(n > max) {
				max = n;
				a[i] = j;
			}
		}
		//printf("%lf\n", max);
		res *= max;
	}
	res = (res * 0.65 - 1) * 2;
	for(int i = 0; i < 3; i++) {
		printf("%c ", s[a[i]]);
	}
	//printf("%lf", res);
	printf("%.2f", res);
	printf("%.2f", res + 0.005);	//dev直接去但是pat四舍五入 
	return 0;
}
