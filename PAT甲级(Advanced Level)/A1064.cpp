#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n, index = 0;
int CBT[maxn], num[maxn];
void inOrder(int root) {
	if(root > n) return;
	inOrder(root * 2);
	CBT[root] = num[index++];
	inOrder(root * 2 + 1);
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	inOrder(1);
	int count = 0;
	for(int i = 1; i <= n; i++) {
		printf("%d", CBT[i]);
		count++;
		if(count < n) printf(" ");
	}
	return 0;
}
