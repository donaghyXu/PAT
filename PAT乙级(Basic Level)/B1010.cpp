#include <cstdio>
int main() {
	int a[1005] = {0};
	int k, e, cnt = 0;
	
	//�������ʽ 
	while(scanf("%d %d", &k, &e) != EOF) {
		a[e] = k;
	}

	//�����󵼲�ͳ�Ʒ�������� 
	for(int i = 1; i <= 1000; i++) {
		a[i - 1] = a[i] * i;
		a[i] = 0; 
		if(a[i - 1] != 0) cnt++;
	}
	
	//�Ӹߵ���ö�����������ϵ����ָ�� 
	if(cnt == 0) printf("0 0");	//������ľ�з����� 
	else {
		for(int i = 1000; i >= 0; i--) {
			if(a[i] != 0) {
				printf("%d %d", a[i], i);
				cnt--;
				if(cnt != 0)	printf(" ");
			}	
		}
	}
	return 0;
} 
