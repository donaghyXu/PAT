#include <cstdio>
const int maxn = 100010;
const int INF = 0x3fffffff;
int a[maxn], leftMax[maxn], rightMin[maxn], res[maxn];
int main() {
	int n, num = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	leftMax[0] = -2;
	for(int i = 1; i < n; i++) {
		if(a[i - 1] > leftMax[i - 1]) leftMax[i] = a[i - 1];
		else leftMax[i] = leftMax[i - 1];
	}
	rightMin[n - 1] = INF;
	for(int i = n - 2; i >= 0; i--) {
		if(a[i + 1] < rightMin[i + 1])	rightMin[i] = a[i + 1];
		else rightMin[i] = rightMin[i + 1];
	}
	for(int i = 0; i < n; i++) {
		if(leftMax[i] < a[i] && rightMin[i] > a[i])
			res[num++] = a[i];
	}
	printf("%d\n", num);
	for(int i = 0; i < num; i++) {
		printf("%d", res[i]);
		if(i != num - 1) printf(" ");
	}
	printf("\n");
	return 0;
	
}
