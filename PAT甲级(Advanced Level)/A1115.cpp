#include <cstdio>
#include <queue>
using namespace std;
int resLevel[1000] = {0};
struct node {
	int data, level;
	node* lchild;
	node* rchild;
};

void insert(node* &root, int data) {
	if(root == NULL) {
		root = new node;
		root->data = data;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(data < root->data) insert(root->lchild, data);
	else insert(root->rchild, data);
}
int maxLevel = -1;
void BFS(node* root) {
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		node* now = q.front();
		q.pop();
		resLevel[now->level]++;
		if(maxLevel < now->level) maxLevel = now->level;
		if(now->lchild != NULL) {
			q.push(now->lchild);
			now->lchild->level = now->level + 1;
		}
		if(now->rchild != NULL) {
			q.push(now->rchild);
			now->rchild->level = now->level + 1;
		}
	}
}
int main() {
	int n, temp;
	scanf("%d", &n);
	node* root = NULL;
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		insert(root, temp);
	}
	root->level = 1;
	BFS(root);
	printf("%d + %d = %d\n", resLevel[maxLevel], resLevel[maxLevel - 1], resLevel[maxLevel] + resLevel[maxLevel - 1]);
 	return 0;
}
