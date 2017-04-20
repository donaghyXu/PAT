#include <cstdio>
int main() {
	int n, cnt = 0;
	int res[3];
	char change[4] = {' ', ' ', 'S', 'B'};	//代表转换后的字符 
	scanf("%d", &n);
	while(n != 0) {
		res[cnt] = n % 10;	//将每位数字逆序存入res数组 
		n /= 10;
		cnt++;	//统计位数 
	}
	
	//百位或十位，分别输出对应数字个数的B或S 
	while(cnt != 1) {
		for(int i = 0; i < res[cnt - 1]; i++) {
			printf("%c", change[cnt]);
		}
		cnt--;
	}
	
	//个位，按序输出 
	if(cnt == 1) {
		for(int i = 1; i <= res[cnt - 1]; i++) {
			printf("%d", i);
		}
	}
	return 0;
} 
