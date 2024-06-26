#include <cstdio>
#include <algorithm>
using namespace std;
struct MoonCake{
	double kuCun, sale, danJia;
}moonCake[1010];

bool cmp(MoonCake a, MoonCake b) {
	return a.danJia > b.danJia;
}

int main() {
	int n;
	double d;
	double res = 0;
	scanf("%d %lf", &n, &d);
	for(int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].kuCun);
	}
	for(int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].sale);
		moonCake[i].danJia = moonCake[i].sale / moonCake[i].kuCun;
	}
	
	sort(moonCake, moonCake + n, cmp);
//	for(int i = 0; i < n; i++) {
//		printf("%lf\n", moonCake[i].danJia);
//	}
	int i = 0;
	while(i < n) {
		if(moonCake[i].kuCun > d) {
			res = res + moonCake[i].danJia * d;
//			printf("kucun: %lf", moonCake[i].kuCun);
			
			break;
		} else {
			res = res + moonCake[i].sale;
			d = d - moonCake[i].kuCun;
			i++;
		}
	}
	printf("%.2f\n", res);
	return 0;
}

