#include <cstdio>
int main() {
	int n, teamScore = 0, max = -1, winTeam;
	int hashTable[1010] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int teamNum, teamMem, memScore;
		scanf("%d-%d %d", &teamNum, &teamMem, &memScore);
		hashTable[teamNum] += memScore;
		if(hashTable[teamNum] > max) {
			max = hashTable[teamNum];
			winTeam = teamNum;
		}
	}
	printf("%d %d", winTeam, max);
	return 0;
}
