#include <cstdio>
int main() {
	int red, green, blue;
	scanf("%d %d %d", &red, &green, &blue);
	char c[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
	int z[2] = {0}, num[3];
	printf("#");
	num[0] = red; num[1] = green; num[2] = blue;
	for(int i = 0; i < 3; i++) {
		int count = 0;
		do{
			z[count++] = num[i] % 13;
			num[i] /= 13;
		}while(num[i] != 0);
		if(z[1] == 0) count++;	
		for(int i = count - 1; i >= 0; i--) {
			printf("%c", c[z[i]]);
		}
	}
	
	return 0;
}
