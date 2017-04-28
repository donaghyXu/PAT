#include <cstdio>
#include <cstring>
int main() {
	int cnt = 0;
	char str[85];
	gets(str);	//获得输入的字符串 
	int len = strlen(str);	//计算字符串的长度 
	char res[85][85];
	int j = 0;
	
	//切割字符串为单词存入二维数组 
	for(int i = 0; i < len; i++) {
		if(str[i] != ' ') {
			res[cnt][j++] = str[i];
		} else {
			res[cnt][j] = '\0';
			cnt++;
			j = 0;			
		}
	} 
	res[cnt][j] = '\0';	//给最后一个单词加上结束符 
	cnt++;
	
	//倒序输出单词 
	for(int i = cnt - 1; i >= 0; i--) {
		printf("%s", res[i]);
		if(i > 0) printf(" ");
	}	
	return 0;
} 
