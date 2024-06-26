#include <cstdio>
int main() {
	int n, num = 1, count = -1, res = 0; char c;
	scanf("%d %c", &n, &c);
	while((2 * res - 1) <= n){
		res += num;
		num += 2;
		count++;
	}
	res = num = 1;
	for(int i = 1; i < count; i++) {
		num = num + 2;
		res += num;                                
	}
	for(int j = 0; j < count; j++) {
		for(int k = 0; k < j; k++) {
			printf(" ");
		}
		for(int k = 0; k < (num - 2 * j); k++) {
			printf("%c", c);
		}
		printf("\n");
	}
	for(int j = 0; j < count - 1; j++) {
		for(int k = 0; k < (num - 3 - 2 * j) / 2; k++) {
			printf(" ");
		}
		for(int k = 0; k < (3 + 2 * j); k++) {
			printf("%c", c);
		}
		printf("\n");
	}
	printf("%d", n - (2 * res - 1));
	return 0;
}
