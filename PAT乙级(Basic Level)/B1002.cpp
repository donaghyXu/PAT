#include <cstdio>
#include <cstring>
const int maxn = 105;	//����maxnΪ105���Դ���100 
int main() {
	char num[maxn];
	char numToChinese[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi",
								"ba", "jiu"};
	int res[3];
	int sum = 0, cnt = 0;
	scanf("%s", num);
	int len = strlen(num);	//�ַ����ĳ���
	for(int i = 0; i < len; i++) {
		sum = sum + (num[i] - '0'); 	//�����ܺ� 
	} 
	if(sum == 0) printf("ling");	//�����Ϊ0��ֱ����� 
	else {
		while(sum != 0) {		//��sum����λ���ϵ����ִ���res���� 
			res[cnt] = sum % 10;
			sum /= 10;
			cnt++;
		}
	}
	for(int i = cnt - 1; i >= 0; i--) {		//�������������Ӧ������ 
		printf("%s", numToChinese[res[i]]);
		if(i != 0) printf(" ");
	}
	return 0;
} 
