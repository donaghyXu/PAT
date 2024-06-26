#include <cstdio>
const int maxN = 100001;
int school[maxN] = {0};
int main() {
	int schNum, n, score, max = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &schNum, &score);
		school[schNum] += score; 
		if(schNum > max) max = schNum;
	}
	int id = 1, maxScore = 0;
	for(int i = 1; i <= max; i++) {
		if(maxScore < school[i]) {
			id = i;
			maxScore = school[i];
		}
	}
	printf("%d %d\n", id, maxScore);
	return 0;
}
	
