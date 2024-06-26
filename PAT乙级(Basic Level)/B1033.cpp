#include <cstdio>
#include <cstring>
int main() {
//	bool hashC[256] = {true};
	bool hashC[256];
	memset(hashC, true, sizeof(hashC));
	char str1[100010], str2[100010];
	gets(str1); gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i++) {
		char c1 = str1[i];
		if(c1 >= 'A' && c1 <= 'Z') c1 += 32;
		hashC[c1] = false;
	}
	for(int i = 0; i < len2; i++) {
		char c2 = str2[i];
//		printf("c:%c ", c2);
		char shift = '+';
		if(c2 >= 'A' && c2 <= 'Z') {
			c2 += 32;
			if(hashC[shift] == false) continue;
		}		
		if(hashC[c2] == true) {
//			printf(" true\n");
			printf("%c",str2[i]);
		}
	}
	return 0;
}
