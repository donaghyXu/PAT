#include <cstdio>
int main() {
	int num[10], n = 0;
	int res[55];
	for(int i = 0; i < 10; i++) {
		scanf("%d", &num[i]);
		n += num[i];
	}
	bool flag = false;
	for(int j = 1; j < 10; j++) {
		if(num[j] != 0) {
			printf("%d", j);
			flag = true;
			num[j]--;
			break;
		}
	}
	for(int j = 0; j < 10; j++) {
		while(num[j] != 0) {
			printf("%d", j);
			num[j]--;
		}
	}
	return 0;
}
