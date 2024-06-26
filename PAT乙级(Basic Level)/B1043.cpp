#include <cstdio>
#include <cstring>
int main() {
	int hashTable[10] = {0};
	char str[10010];
	char str2[7] = {'P', 'A', 'T', 'e', 's', 't'};
	gets(str);
	int sum = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < 6; j++) {
			if(str[i] == str2[j]) {
				hashTable[j]++;
				sum++;
			}
		}
	}
	while(sum > 0) {
		for(int i = 0; i < 6; i++) {
			if(hashTable[i] > 0) {
				printf("%c", str2[i]);
				hashTable[i]--;
				sum--;
			} 
		}
	}
	return 0;
}
