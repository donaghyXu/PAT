#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main() {
	int n1, n2;
	int num1[maxn], num2[maxn];
	long long res = 0;
	scanf("%d", &n1);
	for(int i = 0; i < n1; i++) {
		scanf("%d", &num1[i]);
	}
	scanf("%d", &n2);
	for(int i = 0; i < n2; i++) {
		scanf("%d", &num2[i]);
	}
	sort(num1, num1 + n1);
	sort(num2, num2 + n2);
	
	int i = 0;
	while(i < n1 && i < n2 && num1[i] < 0 && num2[i] < 0) {
		res += num1[i] * num2[i];
		i++;
	}
	i = n1 - 1;
	int j = n2 - 1;
	while(i >= 0 && j >= 0 && num1[i] > 0 && num2[j] > 0) {
		res += num1[i] * num2[j];
		i--;j--;
	}
	printf("%d\n", res);
	return 0;
}
