#include<cstdio>
int main(){
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	int c = a + b;
	int num = 0;
	int res[40];
	int result = 0, p = 1;
	do{
		res[num++] = c % d;
		c = c / d;
	}while(c != 0);
	/*for(int i = 0; i <= num - 1; i++) {
		result = result + res[i] * p;
		p = p * 10;
	}
	printf("%d", result);*/
	for(int i = num - 1; i >= 0; i--) {
		printf("%d", res[i]);
	}
	return 0;
}
