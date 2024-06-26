#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;
struct node{
	vector<int> child;
}Node[maxn];

int minDepth = 100010, count = 0;
void DFS(int root, int depth) {
	if(Node[root].child.size() == 0) {
		if(depth < minDepth) {
			minDepth = depth;
			count = 1;
		} else if(depth == minDepth)
			count++;
		return;
	}
	for(int i = 0; i < Node[root].child.size(); i++) {
		DFS(Node[root].child[i], depth + 1);
	}
}
int main() {
	int n, num;
	double p, r, res;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		if(num != 0) {
			for(int j = 0; j < num; j++) {
				int temp;
				scanf("%d", &temp);
				Node[i].child.push_back(temp);
			}
		}
	}
	DFS(0, 0);
	res = p * pow((1 + r / 100), minDepth);
	printf("%.4f %d", res, count);
	return 0;
}
