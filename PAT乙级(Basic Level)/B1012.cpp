#include <cstdio>
int main() {
	int n, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = -999, temp;
	int cnt[6] = {0};	//ͳ��5��ֱ��ж��ٸ��� 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		
		//��5������ż��֮�� 
		if(temp % 10 == 0) {
			a1 += temp;
			cnt[1]++;
		}
		
		//��5����1��������� 
		if(temp % 5 == 1) {
			if(cnt[2] % 2 == 0) a2 += temp;
			else a2 -= temp;
			cnt[2]++;
		}
		
		//��5����2�����ָ��� 
		if(temp % 5 == 2) {
			a3++;
			cnt[3]++;
		} 
		
		//��5����3����֮�� 
		if(temp % 5 == 3) {
			a4 += temp;
			cnt[4]++;
		}
		
		//��5����4������� 
		if(temp % 5 == 4) {
			if(temp > a5) a5 = temp;
			cnt[5]++;
		} 
	}
	
	if(cnt[1] != 0)	printf("%d ", a1);
	else printf("N ");
	
	if(cnt[2] != 0)	printf("%d ", a2);
	else printf("N ");
	
	if(cnt[3] != 0)	printf("%d ", a3);
	else printf("N ");
	
	if(cnt[4] != 0) 	printf("%.1f ", (double)a4 / cnt[4]);
	else printf("N ");
	
	if(cnt[5] != 0)	printf("%d", a5);
	else printf("N"); 
	return 0;
} 
