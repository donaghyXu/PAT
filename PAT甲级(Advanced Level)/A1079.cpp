#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
const int maxn = 100010;
struct node{
	vector<int> child;
	int supply;
	int level;
}Node[maxn];

void BFS(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
//		printf("level: %d now: %d ", Node[now].level, now);
		for(int i = 0; i < Node[now].child.size(); i++) {
			if(Node[now].child[i] != -1) {
				q.push(Node[now].child[i]);
				Node[Node[now].child[i]].level = Node[now].level + 1;
			}		
		}
	}
}
int main() {
	int n;
	double p, r, res = 0;
	scanf("%d %lf %lf", &n, &p, &r);
	for(int i = 0; i < n; i++) {
		int num, temp;
		scanf("%d", &num);
		for(int j = 0; j < num; j++) {
			scanf("%d", &temp);
			Node[i].child.push_back(temp);
		}
		if(num == 0) {
			scanf("%d", &temp);
			Node[i].child.push_back(-1);
			Node[i].supply = temp;
		}
	}
	Node[0].level = 1;
	BFS(0);
	for(int i = 0; i < n; i++) {
		if(Node[i].child.size() < 2) {
			if(Node[i].child[0] == -1) {
				//printf("supply: %d ", Node[i].level - 1);
				res = res + p * pow((1 + r /100), (double)(Node[i].level - 1)) * Node[i].supply;
			}
		}		
	}
	printf("%.1f\n", res);
	return 0;
}
