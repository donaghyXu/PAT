#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];
int main() {
	int n, num, res = 0;
	scanf("%d", &n);
	int len = n - 1;
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i;
		if(num == i && i != 0)
			len--;
	}
	int k = 1;
	while(len > 0) {
		while(pos[0] != 0) {
			swap(pos[0], pos[pos[0]]);
			res++;
			len--;
		}
		if(pos[0] == 0) {
			while(k < n) {
				if(pos[k] != k) {
					swap(pos[0], pos[k]);
					res++;
					break;
				}
				k++;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}
