#include <cstdio>
int main() {
	int a[1005] = {0};
	int k, e, cnt = 0;
	
	//读入多项式 
	while(scanf("%d %d", &k, &e) != EOF) {
		a[e] = k;
	}

	//进行求导并统计非零项个数 
	for(int i = 1; i <= 1000; i++) {
		a[i - 1] = a[i] * i;
		a[i] = 0; 
		if(a[i - 1] != 0) cnt++;
	}
	
	//从高到底枚举输出非零项系数和指数 
	if(cnt == 0) printf("0 0");	//特例：木有非零项 
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
