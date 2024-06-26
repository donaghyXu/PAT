#include <cstdio>
int main() {
	int n, k, score;
	int hash[110] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &score);
		hash[score]++;
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &score);
		printf("%d", hash[score]);
		if(i < k - 1) printf(" ");
	}
	return 0;
}
