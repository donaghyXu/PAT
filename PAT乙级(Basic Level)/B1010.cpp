//patָ���Ǹ� 
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

/* 
//ţ����ָ���и��� 
#include <cstdio>
int main(void){
	int a[1005][2]={0}, cnt = 0;
	
	//�������ʽ����ͳ�Ƹ��� 
	while(scanf("%d %d", &a[cnt][0], &a[cnt][1]) != EOF) {
		cnt++;
	}
	
	for(int i = 0; i < cnt; i++){
		if(a[i][1] != 0) printf("%d %d", a[i][0] * a[i][1], a[i][1] - 1);	//��ӡ�󵼺�Ķ���ʽ 
		if((i != cnt - 1) && (a[i+1][1] != 0)) printf(" ");	//����ո� 
		if(cnt == 1 && a[i][1]==0) printf("0 0");	//ָ����ϵ������0,��ʾΪ0 0
	}
	return 0;
}
*/
