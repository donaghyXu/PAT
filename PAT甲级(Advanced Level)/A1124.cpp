#include <cstdio>
#include <cstring>
bool isSame(char a[], char b[]) {
	int lenA = strlen(a);
	int lenB = strlen(b);
	if(lenA != lenB) return false;
	else {
		for(int i = 0; i < lenA; i++) {
			if(a[i] != b[i])
				return false;
		}
		return true;
	}
}
int main() {
	int m, n, s;
	char win[1005][25];
	char str[1005][25];
	scanf("%d %d %d", &m, &n, &s);
	int winNum = 0, count = 0;
	for(int i = 1; i <= m; i++) {
		scanf("%s", str[i]);
		if(i < s) continue;
//		printf("%d ", i);
		bool flag;
		if(winNum == 0) {
			count++;
		} else { 
			for(int j = 0; j < winNum; j++) {
				flag = isSame(str[i], win[j]);
				if(flag == true) {
//					printf("true\n");
					break;
				}
					
			}
			if(flag != true) count++;
		}
		if(count % n == 1) {
			printf("%s\n", str[i]);
			int len = strlen(str[i]);
			int j;
			for(j = 0; j < len; j++) {
				win[winNum][j] = str[i][j];
			}
			win[winNum][j] = '\0';
			winNum++;
		}
	}
	if(winNum <= 0) printf("Keep going...\n");
	return 0;
}
