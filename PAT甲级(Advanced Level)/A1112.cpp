#include <cstdio>
#include <cstring>
int main() {
	int k, cnt = 1;
	scanf("%d", &k);
	char str[1010], res[1010];
	scanf("%s", str);
	int hashTable[256] = {0};
	int len = strlen(str);
	int i = 0, j = 0;
	while(i < len) {
		while(j < len && str[i] == str[j]) {
			j++;
		}
		if((j - i) % k != 0)
			hashTable[str[i]] = 1;
		i = j;	
	}
	for(int i = 0; i < len; i++) {
		if(hashTable[str[i]] == 0) {
			printf("%c", str[i]);
			hashTable[str[i]] = -1;
		}			
	}
	printf("\n");
	for(int i = 0; i < len; i++) {
		printf("%c", str[i]);
		if(hashTable[str[i]] != 1)	
			i = i + k - 1;
	}
	printf("\n");
	return 0;
}
