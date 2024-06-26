#include <cstdio>
#include <cstring>
int main() {
	char str1[10010], str2[10010];
	int hashTable[256] = {0};
	gets(str1); gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len2; i++) {
		hashTable[str2[i]]++;
	}
	for(int i = 0; i < len1; i++) {
		if(hashTable[str1[i]] == 0) {
			printf("%c", str1[i]);
		}
	}
	return 0;
}
