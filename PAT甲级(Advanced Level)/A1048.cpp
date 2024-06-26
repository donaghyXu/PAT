#include <cstdio>
int main() {
	int n, m, a;
	scanf("%d %d", &n, &m);
	int hashTable[1010];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		hashTable[a]++;
	}
	for(int i = 0; i < 1010; i++) {
		if(hashTable[i] && hashTable[m - i]) {
			if(i == m - i && hashTable[i] <= 1) {
				continue;
			}
			printf("%d %d\n", i, m - i);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}
