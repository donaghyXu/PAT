#include <cstdio>
int a[105];	//����һ������a 
int main() {
	int n, m, cnt = 0;
	scanf("%d %d", &n, &m);
	m = m % n;	//���m����n����ȡ���� 
	//����n������ 
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = n - m; i < n; i++) {
		printf("%d", a[i]);
		cnt++;	//ͳ��������� 
		if(cnt < n) printf(" ");	//�������ĸ���С��n����Ҫ����ո���ͬ 
	}
	
	for(int i = 0; i < (n - m); i++) {
		printf("%d", a[i]);
		cnt++;
		if(cnt < n) printf(" "); 
	} 
	return 0;
} 
