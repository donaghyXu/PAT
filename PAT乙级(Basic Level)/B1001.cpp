#include <cstdio>
int main() {
	int n, step = 0;
	scanf("%d", &n);
	while(n != 1) {					//n��Ϊ1ʱѭ�� 
		if(n % 2 == 0) {			//nΪż�� 
			n /= 2;
			step++;
		} else {					//nΪ���� 
			n = (3 * n + 1) / 2;
			step++;
		}
	}
	printf("%d\n", step);			//������� 
	return 0;
}
