#include <cstdio>
bool Judge(int z[], int count) {
	for(int i = 0; i <= count / 2; i++) {
		if(z[i] != z[count - i - 1]) 
			return false;
	}
	return true;
}
int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	int z[40], count = 0;
	do {
		z[count++] = n % b;
		n /= b;
	}while(n != 0);
	bool flag = Judge(z,count);
	if(flag == true) printf("Yes\n");
	else printf("No\n");
	for(int i = count - 1; i >= 0; i--) {
		printf("%d", z[i]);
		if(i != 0) printf(" ");
	}
	return 0;
}
