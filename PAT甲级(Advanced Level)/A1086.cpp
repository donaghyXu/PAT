#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
const int maxn = 35;
int in[maxn], pre[maxn];
stack<int> s;
struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* create(int preL, int preR, int inL, int inR) {
	if(preL > preR) return NULL;
	node* root = new node;
	root->data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == pre[preL]) break;
	}
	int numLeft = k - inL;
	root->lchild = create(preL + 1, preL + numLeft, inL, k - 1);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, inR);
	return root;
}

int num = 0;
void postOrder(node* root, int n) {
	if(root == NULL) return;
	postOrder(root->lchild, n);
	postOrder(root->rchild, n);
	printf("%d", root->data);
	num++;
	if(num < n) printf(" ");
}
int main() {
	int n, x;
	char str[5];
	scanf("%d", &n);
	int k = 2 * n, preIndex = 0, inIndex = 0;
	while(k) {
		scanf("%s", str);
		if(strcmp(str, "Push") == 0) {
			scanf("%d", &x);
			pre[preIndex++] = x;
			s.push(x);
		} else {
			in[inIndex++] = s.top();
			s.pop();
		}
		k--;
	}
	node * root = create(0, n - 1, 0, n - 1);
	postOrder(root, n);
	return 0;
}
