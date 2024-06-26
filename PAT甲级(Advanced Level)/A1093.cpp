#include <cstdio>
#include <cstring>
int main() {
	char str[100010];
	const int a = 1000000007;
	int leftP[100010] = {0};
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if(i > 0) {
			leftP[i] = leftP[i - 1];
		}
		if(str[i] == 'P')
			leftP[i]++;
	}
	int res = 0, rightP = 0;
	for(int i = len - 1; i >= 0; i--) {
		if(str[i] == 'T')
			rightP++;
		else if(str[i] == 'A')
			res = (res + leftP[i] * rightP) % a;
	}
	printf("%d\n", res);
	return 0;
}
