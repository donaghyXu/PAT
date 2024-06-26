#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, s;
const int maxn = 105;
int path[maxn];
struct node{
	int weight;
	vector<int> child;
}Node[maxn];

bool cmp(int a, int b) {
	return Node[a].weight > Node[b].weight;
}
void dfs(int index, int numNode, int sum) {
	if(sum > s) return;
	if(sum == s) {
		if(Node[index].child.size() > 0) return;
		else {
			for(int i = 0; i < numNode; i++) {
				printf("%d", Node[path[i]].weight);
				if(i < numNode - 1) printf(" ");
				else printf("\n");
			}
		}
		return;
	}
	for(int i = 0; i < Node[index].child.size(); i++) {
		int child = Node[index].child[i];
		path[numNode] = child;
		dfs(child, numNode + 1, sum + Node[child].weight);
	}
}
int main() {
	
	scanf("%d %d %d", &n, &m, &s);
	for(int i = 0; i < n; i++) {
		scanf("%d", &Node[i].weight);
	}
	for(int i = 0; i < m; i++) {
		int num1, num2, num3;
		scanf("%d %d", &num1, &num2);
		for(int j = 0; j < num2; j++) {
			scanf("%d", &num3);
			Node[num1].child.push_back(num3);
		}
		sort(Node[num1].child.begin(), Node[num1].child.end(), cmp);
	}
	path[0] = 0;
	dfs(0, 1, Node[0].weight);
	return 0;
}
