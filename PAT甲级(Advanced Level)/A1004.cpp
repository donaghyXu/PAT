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

int maxLevel = -1;
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		if(Node[now].child.size() == 0) 
			hashTable[Node[now].level]++;
		if(maxLevel < Node[now].level) maxLevel = Node[now].level;
//		printf("%d level:%d  size:%d\n", now, Node[now].level, Node[now].child.size());
		for(int i = 0; i < Node[now].child.size(); i++) {
			q.push(Node[now].child[i]);
			Node[Node[now].child[i]].level = Node[now].level + 1;
		}		
	}
}
int main() {
	int n, m, index, num;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &index, &num);
		for(int j = 0; j < num; j++) {
			int temp;
			scanf("%d", &temp);
			Node[index].child.push_back(temp);
		}
	}
	Node[1].level = 0;
	BFS(1);
	for(int i = 0; i <= maxLevel; i++) {
		printf("%d", hashTable[i]);
		if(i < maxLevel) printf(" ");
	}
	return 0;
}
