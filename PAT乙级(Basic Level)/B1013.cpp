#include <cstdio>
#include <cmath>
int a[999999];	//����һ���Ƚϴ������ 
int m, n;

//�ж��Ƿ������� 
bool isPrime(int n) {
	if(n == 1) return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

//�����ǰN�������������� 
void findPrime() {
	int cnt = 1;	//ͳ�Ƹ��� 
	for(int i = 1; i <= 999999; i++) {
		if(isPrime(i)) a[cnt++] = i;	//���������������� 
		if(cnt > n) break;
	}
}
int main() {
	int p = 1;	//����ÿ10�����еĸ�ʽ 
	scanf("%d %d", &m, &n);
	findPrime();	//���
	
	//��ӡ��m~n������ 
	for(int i = m; i <= n; i++) {
		printf("%d", a[i]);
		if(p % 10 != 0 && i < n) printf(" ");	//p����10�ı����Ҳ������һ������ո� 
		else printf("\n");
		p++;
	}
	return 0;
} 
