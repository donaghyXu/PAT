#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 110;
int hashTable[maxn] = {0};
struct node{
	vector<int> child;
	int level;
}Node[maxn];

void BFS(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		hashTable[Node[now].level]++;
		q.pop();
		for(int i = 0; i < Node[now].child.size(); i++) {
			q.push(Node[now].child[i]);
			Node[Node[now].child[i]].level = Node[now].level + 1;
		}
	}
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int index, num, temp;
		scanf("%d %d", &index, &num);
		for(int j = 0; j < num; j++) {
			scanf("%d", &temp);
			Node[index].child.push_back(temp);
		}
	}
	Node[1].level = 1;
	BFS(1);
	int maxValue = 0, maxLevel = -1;
	for(int i = 1; i < maxn; i++) {
		if(hashTable[i] > maxValue) {
			maxLevel = i;
			maxValue = hashTable[i];
		}
	}
	printf("%d %d", maxValue, maxLevel);
	return 0;
}
