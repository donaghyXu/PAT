#include <cstdio>
#include <cstring>
int main() {
	char str[100], res[40][40];
	scanf("%s", str);
//	gets(str);
	int N = strlen(str);
	int n1 = (N + 2) / 3;
	int n3 = n1;
	int n2 = N - n1 - n3 + 2;
	for(int i = 1; i <= n1; i++) {
		for(int j = 1; j <= n2; j++) {
			res[i][j] = ' ';
		}
	}
	int pos = 0;
	for(int i = 1; i <= n1; i++) {
		res[i][1] = str[pos++];
	}
	for(int i = 2; i <= n2; i++) {
		res[n1][i] = str[pos++];
	}
	for(int i = n3 - 1; i >= 1; i--) {
		res[i][n2] = str[pos++];
	}
	for(int i = 1; i <= n1; i++) {
		for(int j = 1; j <= n2; j++) {
			printf("%c", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
