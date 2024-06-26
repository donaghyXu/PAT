#include <cstdio>
const int N = 54;
char c[5] = {'S', 'H', 'C', 'D', 'J'};
int main() {
	int n;
	int start[N + 1], end[N + 1], next[N + 1];
	scanf("%d", &n);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &next[i]);
	}
	for(int i = 1; i <= N; i++) {
		start[i] = i;
	}
	for(int i = 0; i < n; i++) {
		for(int i = 1; i <= N; i++) {
			end[next[i]] = start[i];
		}
		for(int i = 1; i <= N; i++) {
			start[i] = end[i];
		}
	}
	for(int i = 1; i <= N; i++) {
		printf("%c%d", c[(start[i] - 1) / 13], (start[i] - 1) % 13 + 1);
		if(i < N) printf(" ");
	}
	return 0;
}
