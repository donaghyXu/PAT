#include<cstdio>
int main() {
	int a1, b1, c1;
	int a2, b2, c2;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int price = (a1 * 17 + b1) * 29 + c1;
	int money = (a2 * 17 + b2) * 29 + c2;
	int res = money - price;
	if(res < 0) {
		printf("-");
		res = -res;
	}
	printf("%d.%d.%d", res / (17 * 29), res % (17 * 29) / 29, res % 29);
	return 0;
}
