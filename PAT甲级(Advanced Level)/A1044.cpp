#include <cstdio>
int sum[100010];
int upper_bound(int left, int right, int x) {
	while(left < right) {
		int mid = (left + right) / 2;
		if(sum[mid] > x) right = mid;
		else left = mid + 1;
	}
	return left;
}

int main() {
	int n, m, nearM = 100000010;
	scanf("%d%d", &n, &m);
	sum[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] = sum[i] + sum[i - 1];
	}
	
	for(int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + m);
		if(sum[j - 1] - sum[i - 1] == m) {
			nearM = m;
			break;
		} else if(j <= n && sum[j] - sum[i - 1] < nearM)
			nearM = sum[j] - sum[i - 1];
	} 
	
	for(int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + nearM);
		if(sum[j - 1] - sum[i - 1] == nearM) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}
