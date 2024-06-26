#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	int a1, a2, b1, b2, res1 = 0, res2 = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		if(a2 == (a1 + b1) && b2 != (a1 + b1))
			res2++;
		else if(a2 != (a1 + b1) && b2 == (a1 + b1))
			res1++;
	}
	printf("%d %d", res1, res2);
	return 0;
}
