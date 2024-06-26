#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
const int maxn = 35;
int n;
int post[maxn], in[maxn];
struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* create(int postL, int postR, int inL, int inR) {
	if(postL > postR) return NULL;
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == post[postR]) break;
	}
	int numleft = k - inL;
	root->lchild = create(postL, postL + numleft - 1, inL, k - 1);
	root->rchild = create(postL + numleft, postR - 1, k + 1, inR);
	return root;
}

vector<int> res;
void ZigZagBFS(node* root) {		
	stack<node*> s1;
	stack<node*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()) {
		while(!s1.empty()) {
			node* now = s1.top();
			res.push_back(now->data);
			s1.pop();			
			if(now->rchild != NULL) s2.push(now->rchild);
			if(now->lchild != NULL) s2.push(now->lchild);
		}
		while(!s2.empty()) {
			node* now = s2.top();
			res.push_back(now->data);
			s2.pop();
			if(now->lchild != NULL) s1.push(now->lchild);
			if(now->rchild != NULL) s1.push(now->rchild);
		}
	}
//	while(!q.empty()) {
//		node* now = q.front();
//		q.pop();
//		num++;		
//		printf("%d ", now->data);
//		if(num < n) printf(" ");
//		if(now->lchild != NULL) q.push(now->lchild);
//		if(now->rchild != NULL) q.push(now->rchild);
//	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	node* root = create(0, n - 1, 0, n - 1);
	ZigZagBFS(root);
//	printf("%d\n", res.size());
	for(int i = 0; i < res.size(); i++) {
		printf("%d", res[i]);
		if(i < n - 1) printf(" ");
	}
	return 0;
	
}
