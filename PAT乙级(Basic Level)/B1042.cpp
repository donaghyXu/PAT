#include <cstdio>
#include <cstring>
int main() {
	char str[1010];
	int hashTable[256] = {0};
	int max = -1;
	char c;
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
		if(str[i] >= 'a' && str[i] <= 'z') hashTable[str[i]]++;
		if(hashTable[str[i]] > max) {
			max = hashTable[str[i]];
			c = str[i];
		} else if(hashTable[str[i]] == max && str[i] < c) {
			c = str[i];
		}	
	}
	printf("%c %d", c, max);
	return 0;
}
