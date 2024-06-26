#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], in[maxn], post[maxn];
int n;
node* create(int postL, int postR, int inL, int inR) {
	if(postL > postR) return NULL;
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k = inL; k < inR; k++) {
		if(in[k] == post[postR]) break;
	}
	int numLeft = k - inL;
	root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
	root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}
int main() {
	
	return 0;
}
