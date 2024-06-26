#include <cstdio>
#include <cstring>
int w[19] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char check[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main() {
	int n;
	char str[20];
	bool flag = true;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int j, sum = 0;
		scanf("%s", str);
		int len = strlen(str);
		for(j = 0; j < 17; j++) {
			if(!(str[j] >= '0' && str[j] <= '9')) break;
			sum = sum + (str[j] - '0') * w[j];
		}
//		printf("sum:%d, j:%d\n", sum, j);
//		printf("yu:%d, check[6]:%d\n", sum % 11, check[6]);
//		printf("check:%d, x:%d\n", check[sum % 11], str[17]);
		if(j < 17) {
			flag = false;
			printf("%s\n", str);
		} else {
			if(check[sum % 11] != str[17]) {
				flag = false;
				printf("%s\n", str);
			}
		}
	}
	if(flag == true) 
		printf("All passed\n");
	return 0;
}
