#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 15;
bool notRoot[maxn] = {0};
queue<int> q;
struct node{
	int lchild;
	int rchild;
}Node[maxn];

int strToNum(char c) {
	if(c == '-') return -1;
	else {
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

int num;
void BFS(int root, int n) {
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d", now);
		num++;
		if(num < n) printf(" ");
		else printf("\n");
		if(Node[now].lchild != -1) q.push(Node[now].lchild);
		if(Node[now].rchild != -1) q.push(Node[now].rchild);
	}
}

void postOrder(int root) {
	if(root == -1) return;
	postOrder(Node[root].lchild);
	postOrder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}

void inOrder(int root, int n) {
	if(root == -1) return;
	inOrder(Node[root].lchild, n);
	printf("%d", root);
	num++;
	if(num < n) printf(" ");
	else printf("\n");
	inOrder(Node[root].rchild, n);
}
int main() {
	int n;
	scanf("%d", &n);
	char str1, str2;
	for(int i = 0; i < n; i++) {
		scanf("%*c%c %c", &str1, &str2);		
		Node[i].lchild = strToNum(str1);
		Node[i].rchild = strToNum(str2);
	}
	int root;
	for(int i = 0; i < n; i++) {
		if(notRoot[i] != true) {
			root = i;
			break;	
		}		
	}
//	printf("root: %d", root);
	postOrder(root);
	num = 0;
	BFS(root, n);
	num = 0;
	inOrder(root, n);
	return 0;
}
