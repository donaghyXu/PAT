#include <cstdio>
int main() {
	int n;
	int num[110];
	num[0] = 0;
	int up = 6, down = 4, stay = 5, res = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		if(num[i] > num[i - 1]) 
			res += (num[i] - num[i - 1]) * up;
		else
			res += (num[i - 1] - num[i]) * down;
		res += stay;
	}
	printf("%d\n", res);
	return 0;
}
