#include <cstdio>
#include <cstring>
int main() {
	int cnt = 0;
	char str[85];
	gets(str);	//���������ַ��� 
	int len = strlen(str);	//�����ַ����ĳ��� 
	char res[85][85];
	int j = 0;
	
	//�и��ַ���Ϊ���ʴ����ά���� 
	for(int i = 0; i < len; i++) {
		if(str[i] != ' ') {
			res[cnt][j++] = str[i];
		} else {
			res[cnt][j] = '\0';
			cnt++;
			j = 0;			
		}
	} 
	res[cnt][j] = '\0';	//�����һ�����ʼ��Ͻ����� 
	cnt++;
	
	//����������� 
	for(int i = cnt - 1; i >= 0; i--) {
		printf("%s", res[i]);
		if(i > 0) printf(" ");
	}	
	return 0;
} 
