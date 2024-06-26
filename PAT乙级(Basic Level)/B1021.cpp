#include <cstdio>
#include <cstring>
int main() {
	/*long long n;
	scanf("%lld", &n);
	int z[1010], count = 0;
	while(n != 0) {
		z[count++] = n % 10;
		n /= 10;
	}
//	printf("%d\n", count);
//	for(int i = 0; i < count; i++) {
//		printf("%d", z[i]);
//	}
	int res[10] = {0};
	for(int i = 0; i < count; i++) {
		res[z[i]]++;
	}
	for(int i = 0; i < 10; i++) {
		if(res[i] != 0) {
			printf("%d:%d\n", i, res[i]);
		}
	}*/
	char str[1010];
	gets(str);
	int len = strlen(str);
	
	int res[10] = {0};
	for(int i = 0; i < len; i++) {
		res[str[i] - '0']++;
	}
	for(int i = 0; i < 10; i++) {
		if(res[i] != 0) {
			printf("%d:%d\n", i, res[i]);
		}
	}
	return 0;
}
