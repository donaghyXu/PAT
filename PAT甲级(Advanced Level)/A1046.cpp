#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, m, sum = 0;
	int d[100010];
	int mm[10010][3] = {0};
	int dis[10010];
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		sum += d[i];
		dis[i] = sum;
	}
	//printf("%d\n", sum);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d", &mm[i][1], &mm[i][2]);
		if(mm[i][1] > mm[i][2]) swap(mm[i][1],mm[i][2]);
		mm[i][0] = dis[mm[i][2] - 1] - dis[mm[i][1] - 1];
		//printf("%d\n", mm[i][0]);
		mm[i][0] = min(mm[i][0],sum - mm[i][0]);	
	}
	
	for(int i = 1; i <= m; i++) {
		printf("%d\n", mm[i][0]);
	}
	return 0;
}
