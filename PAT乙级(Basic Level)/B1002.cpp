#include <cstdio>
#include <cstring>
const int maxn = 105;	//定义maxn为105，稍大于100 
int main() {
	char num[maxn];
	char numToChinese[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi",
								"ba", "jiu"};
	int res[3];
	int sum = 0, cnt = 0;
	scanf("%s", num);
	int len = strlen(num);	//字符串的长度
	for(int i = 0; i < len; i++) {
		sum = sum + (num[i] - '0'); 	//数字总和 
	} 
	if(sum == 0) printf("ling");	//如果和为0，直接输出 
	else {
		while(sum != 0) {		//将sum各个位数上的数字存在res数组 
			res[cnt] = sum % 10;
			sum /= 10;
			cnt++;
		}
	}
	for(int i = cnt - 1; i >= 0; i--) {		//根据数字输出相应的中文 
		printf("%s", numToChinese[res[i]]);
		if(i != 0) printf(" ");
	}
	return 0;
} 
