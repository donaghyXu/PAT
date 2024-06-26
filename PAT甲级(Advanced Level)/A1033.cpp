#include <cstdio>
#include <algorithm>
using namespace std;
struct GasStation{
	double pi;
	double di;
}gs[510];

bool cmp(GasStation a, GasStation b) {
	return a.di < b.di;
}
int main() {
	double cMax, d, davg, res = 0;
	int n, minGs;
	scanf("%lf %lf %lf %d", &cMax, &d, &davg, &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf %lf", &gs[i].pi, &gs[i].di);
	}
	sort(gs, gs + n, cmp);

	int i = 0, k;
	double max = cMax * davg;
	bool flag; double nowTank = 0;
	if(gs[i].di == 0) {
		while(i < n) {
//			k = -1;
			double min = gs[i].pi;
			double min2;
			if(i + 1 < n) {
				flag = false;
				min2 = gs[i + 1].pi;
				minGs = i + 1;
			}
			for(int j = i + 1; j < n; j++) {
				if((gs[j].di - gs[i].di) <= max) {
					if(gs[j].pi < min) {
						minGs = j;
//						k = j;
						flag = true;
						break;
					} else if(gs[j].pi < min2){
						min2 = gs[j].pi;
						minGs = j;
//						k = j;
						flag = false;
					}				
				} else {
					break;
				}
			}
			if(minGs == i || k == -1) break;
			double need = (gs[minGs].di - gs[i].di) / davg; 
			if(flag == true) {
				if(nowTank < need) {
					res += (need - nowTank) * gs[i].pi;
					nowTank = 0;
				}					
				else nowTank -= need;
			} else {
				res += (max / davg - nowTank) * gs[i].pi;
				nowTank = max / davg - need;
			}
			i = minGs;
		}

	} else {
		printf("The maximum travel distance = 0\n");
		return 0;
	}
//	printf("I:%d\n", i);
	if((gs[i].di + max) < d) printf("The maximum travel distance = %.2f\n", gs[i].di + max);
	else {
		double need = (d - gs[i].di) / davg;
		if(nowTank < need) res += (need - nowTank) * gs[i].pi;
		printf("%.2f\n", res);
	}
	return 0;
}
