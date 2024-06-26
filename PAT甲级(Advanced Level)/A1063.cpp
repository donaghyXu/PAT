#include <cstdio>
#include <set>
using namespace std;
set<int> st[55];
void compare(int num1, int num2) {
	int totalNum = st[num2].size(), sameNum = 0;
	for(set<int>::iterator it = st[num1].begin(); it != st[num1].end(); it++) {
		if(st[num2].find(*it) != st[num2].end()) sameNum++;
		else totalNum++;
	}
	printf("%.1f%\n", sameNum * 100.0 / totalNum );
}
int main() {
	int n, num, k, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for(int j = 0; j < m; j++) {
			scanf("%d", &num);
			st[i].insert(num);
		}
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++) {
		int num1, num2;
		scanf("%d %d", &num1, &num2);
		compare(num1, num2);
	}
	return 0;
}
