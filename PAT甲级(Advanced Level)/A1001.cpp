#include <cstdio>
int res[10];
int cnt = 0;
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int sum = a + b;
	if(sum < 0) {
		printf("-");
		sum = -sum;
	} else if(sum == 0) {
		printf("0");
		return 0;
	}		
	while(sum != 0) {
		res[cnt++] = sum % 10;
		sum /= 10;
	}
	for(int i = cnt - 1; i >= 0; i--) {
		printf("%d", res[i]);
		if(i % 3 == 0 && i != 0)
			printf(",");
	}
	return 0;
}
