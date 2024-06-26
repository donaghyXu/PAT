#include <cstdio>
#include <queue>
using namespace std;
struct Mouse {
	int weight;
	int level;
}mouse[1010];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	queue<int> q;
	int order, group;
	for(int i = 0; i < n; i++) {
		scanf("%d", &mouse[i].weight);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &order);
		q.push(order);
	}
	int temp = n;
	while(q.size() != 1) {
		if(temp % k == 0) group = temp / k;
		else group = temp / k + 1;
		for(int i = 0; i < group; i++) {
			int m = q.front();
			for(int j = 0; j < k; j++) {
				if(i * k + j >= temp) break;
				int s = q.front();
				mouse[s].level = group + 1;
				if(mouse[s].weight > mouse[m].weight) {			
					m = s;
				}
				q.pop();
			}
			q.push(m);
		}
		temp = group;
	}
	mouse[q.front()].level = 1;
	for(int i = 0; i < n; i++) {
		printf("%d", mouse[i].level);
		if(i < n - 1) printf(" ");
	}
	return 0;
}
