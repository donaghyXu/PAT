#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	long long p;
	long long num[100010];
	scanf("%d %lld", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &num[i]);
	}
	sort(num, num + n);
	int res = 0;
	for(int i = 0; i < n; i++) {
		int j = upper_bound(num + i + 1, num + n, num[i] * p) - num;
		res = max(res, j - i);
	}
	printf("%d\n", res);
	return 0;
}

