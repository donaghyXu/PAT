#include <cstdio>
#include <algorithm>
using namespace std;
int num[100010];
int main() {
	int n, sum = 0, sumA = 0, sumB;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
	}
	sort(num, num + n);
	for(int i = 0; i < n / 2; i++) {
		sumA += num[i];
	}
	sumB = sum - sumA;
	if(n % 2 == 0) {
		printf("0 %d\n", sumB - sumA);
	} else {
		printf("1 %d\n", sumB - sumA);
	}
	return 0;
}
