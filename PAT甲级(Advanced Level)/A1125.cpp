#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, a[10010];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int res = (a[0] + a[1]) / 2;
	for(int i = 2; i < n; i++) {
		res =  (int)((res + a[i]) / 2);
	}
	printf("%d", res);
	return 0;
}
