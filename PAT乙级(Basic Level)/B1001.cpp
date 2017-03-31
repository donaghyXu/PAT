#include <cstdio>
int main() {
	int n, step = 0;
	scanf("%d", &n);
	while(n != 1) {					//n不为1时循环 
		if(n % 2 == 0) {			//n为偶数 
			n /= 2;
			step++;
		} else {					//n为奇数 
			n = (3 * n + 1) / 2;
			step++;
		}
	}
	printf("%d\n", step);			//输出步数 
	return 0;
}
