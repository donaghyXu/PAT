#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int arrayToNum(int num[]) {
	int res = 0;
	for(int i = 0; i < 4; i++) {
		res = res * 10 + num[i];	
	}
	return res;
}

void numToArray(int n, int num[]) {
	for(int i = 0; i < 4; i++) {
		num[i] = n % 10;
		n /= 10;
	}
}
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	scanf("%d", &n);
	int num[10];
	int res = -1;
	bool flag = true;
	numToArray(n, num);
	for(int i = 1; i < 4; i++) {
		if(num[i] != num[i - 1]) flag = false;
	}
	if(flag == true) {
		printf("%04d - %04d = 0000\n", n, n);
		return 0;
	}
	while(res != 6174) {
		numToArray(n, num);
		sort(num, num + 4, cmp);
		int num1 = arrayToNum(num);
		sort(num, num + 4);
		int num2 = arrayToNum(num);
		res = num1 - num2;
		printf("%04d - %04d = %04d\n", num1, num2, res);
		n = res;
	}
	return 0;
}
