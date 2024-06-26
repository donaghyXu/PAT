#include <cstdio>
#include <cstring>
int main() {
	int hashTable[256] = {0};
	int lack = 0;
	char present[1010], target[1010];
	gets(present); gets(target);
	int len1 = strlen(present);
	int len2 = strlen(target);
	for(int i = 0; i < len1; i++) {
		hashTable[present[i]]++;
	}
	for(int i = 0; i < len2; i++) {
		if(hashTable[target[i]] > 0) hashTable[target[i]]--;
		else lack++;
	}
	if(lack > 0) {
		printf("No %d", lack);
	} else {
		printf("Yes %d", len1 - len2);
	}
	return 0;
}
