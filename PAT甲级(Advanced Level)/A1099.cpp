#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Node {
	int data;
	int lchild, rchild;
}node[110];
int num[110];
int index = 0;
void inOrder(int root) {
	if(root == -1) return;
	inOrder(node[root].lchild);
	node[root].data = num[index++];
	inOrder(node[root].rchild);
}
int n, cnt = 0;
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d", node[now].data);
		cnt++;
		if(cnt < n) printf(" ");
		if(node[now].lchild != -1) q.push(node[now].lchild);
		if(node[now].rchild != -1) q.push(node[now].rchild);
	}
}
int main() {

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &node[i].lchild, &node[i].rchild);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	inOrder(0);
	BFS(0);
	return 0;
}
