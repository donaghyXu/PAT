#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[110][260];
void reverse(char c[]) {
	int len = strlen(c);
	for(int i = 0; i < len / 2; i++) {
		swap(c[i], c[len - 1 - i]);
	}
}
int main() {
	int n, minLen = 999, cnt = 0;
	scanf("%d", &n);
	getchar();
	for(int i = 0 ; i < n; i++) {
		gets(str[i]);
		reverse(str[i]);
		int len = strlen(str[i]);
		if(len < minLen) minLen = len;
	}
//	printf("minLen: %d", minLen);
	for(int i = 0; i < minLen; i++) {
		bool flag = true;
		for(int j = 1; j < n; j++) {
			if(str[j][i] != str[j - 1][i]) {
				flag = false;
				break;
			}				
		}
		if(flag == true) cnt++;
		else break;
	}
	if(cnt == 0) printf("nai\n");
	else {
		for(int i = cnt - 1; i >= 0; i--) {
			printf("%c", str[0][i]);
		}
		printf("\n");
	}
	return 0;
}
