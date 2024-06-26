#include <cstdio>
int main() {
	int col,row;
	char c;
	scanf("%d %c", &col, &c);
	if(col % 2 == 0) {
		row = col / 2;
	}else {
		row = col / 2 + 1;
	}
	for(int j = 0; j < col; j++) {
			printf("%c", c);
	}
	printf("\n");
	for(int i = 0; i < row - 2; i++) {
		printf("%c", c);
		for(int j = 0; j < col - 2; j++) {
			printf(" ");
		}
		printf("%c\n", c);
	}
	for(int j = 0; j < col; j++) {
			printf("%c", c);
	}
	return 0;
}
