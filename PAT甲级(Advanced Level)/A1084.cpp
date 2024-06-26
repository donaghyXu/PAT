#include <cstdio>
#include <cstring>
int main() {
	char str1[85], str2[85];
	bool hashC[128] = {false};
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i++) {
		char testC1 = str1[i];
		if(testC1 >= 'a' && testC1 <= 'z')
			testC1 = testC1 - 32;
			
		int j;
		for(j = 0; j < len2; j++) {
			char testC2 = str2[j];
			if(testC2 >= 'a' && testC2 <= 'z')
				testC2 = testC2 - 32;
			if(testC1 == testC2) {
				break;
			}
		}
		if(j == len2 && hashC[testC1] == false) {
			printf("%c", testC1);
			hashC[testC1] = true;
		}		
	}
	return 0;
}
