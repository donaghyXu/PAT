#include <cstdio>
int main() {
	int n, cnt = 0;
	int res[3];
	char change[4] = {' ', ' ', 'S', 'B'};	//����ת������ַ� 
	scanf("%d", &n);
	while(n != 0) {
		res[cnt] = n % 10;	//��ÿλ�����������res���� 
		n /= 10;
		cnt++;	//ͳ��λ�� 
	}
	
	//��λ��ʮλ���ֱ������Ӧ���ָ�����B��S 
	while(cnt != 1) {
		for(int i = 0; i < res[cnt - 1]; i++) {
			printf("%c", change[cnt]);
		}
		cnt--;
	}
	
	//��λ��������� 
	if(cnt == 1) {
		for(int i = 1; i <= res[cnt - 1]; i++) {
			printf("%d", i);
		}
	}
	return 0;
} 
